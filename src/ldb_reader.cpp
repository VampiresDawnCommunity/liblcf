/*
 * This file is part of liblcf. Copyright (c) 2020 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#include <fstream>
#include <cerrno>
#include <cstring>

#include "lcf/ldb/reader.h"
#include "lcf/ldb/chunks.h"
#include "lcf/reader_util.h"
#include "reader_struct.h"

namespace lcf {

void LDB_Reader::PrepareSave(rpg::Database& db) {
	++db.system.save_count;
}

std::unique_ptr<lcf::rpg::Database> LDB_Reader::Load(const std::string& filename, const std::string& encoding) {
	std::ifstream stream(filename.c_str(), std::ios::binary);
	if (!stream.is_open()) {
		fprintf(stderr, "Failed to open LDB file `%s' for reading : %s\n", filename.c_str(), strerror(errno));
		return nullptr;
	}
	return LDB_Reader::Load(stream, encoding);
}

bool LDB_Reader::Save(const std::string& filename, const lcf::rpg::Database& db, const std::string& encoding, SaveOpt opt) {
	std::ofstream stream(filename.c_str(), std::ios::binary);
	if (!stream.is_open()) {
		fprintf(stderr, "Failed to open LDB file `%s' for writing : %s\n", filename.c_str(), strerror(errno));
		return false;
	}
	return LDB_Reader::Save(stream, db, encoding, opt);
}

bool LDB_Reader::SaveXml(const std::string& filename, const lcf::rpg::Database& db) {
	std::ofstream stream(filename.c_str(), std::ios::binary);
	if (!stream.is_open()) {
		fprintf(stderr, "Failed to open LDB XML file `%s' for writing : %s\n", filename.c_str(), strerror(errno));
		return false;
	}
	return LDB_Reader::SaveXml(stream, db);
}

std::unique_ptr<lcf::rpg::Database> LDB_Reader::LoadXml(const std::string& filename) {
	std::ifstream stream(filename.c_str(), std::ios::binary);
	if (!stream.is_open()) {
		fprintf(stderr, "Failed to open LDB XML file `%s' for reading : %s\n", filename.c_str(), strerror(errno));
		return nullptr;
	}
	return LDB_Reader::LoadXml(stream);
}

std::unique_ptr<lcf::rpg::Database> LDB_Reader::Load(std::istream& filestream, const std::string& encoding) {
	LcfReader reader(filestream, encoding);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't parse database file.\n");
		return nullptr;
	}
	std::string header;
	reader.ReadString(header, reader.ReadInt());
	if (header.length() != 11) {
		LcfReader::SetError("This is not a valid RPG2000 database.\n");
		return nullptr;
	}
	if (header != "LcfDataBase") {
		fprintf(stderr, "Warning: This header is not LcfDataBase and might not be a valid RPG2000 database.\n");
	}
	auto db = std::make_unique<lcf::rpg::Database>();
	db->ldb_header = header;
	TypeReader<rpg::Database>::ReadLcf(*db, reader, 0);

	// Delayed initialization of some actor fields because they are engine
	// dependent
	for (auto& actor: db->actors) {
		actor.Setup(db->system.ldb_id == 2003);
	}

	return db;
}

bool LDB_Reader::Save(std::ostream& filestream, const lcf::rpg::Database& db, const std::string& encoding, SaveOpt opt) {
	LcfWriter writer(filestream, db.system.ldb_id == 2003, encoding);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't parse database file.\n");
		return false;
	}
	std::string header;
	if ( db.ldb_header.empty() || !bool(opt & SaveOpt::ePreserveHeader)) {
		header = "LcfDataBase";
	} else {
		header= db.ldb_header;
	}
	writer.WriteInt(header.size());
	writer.Write(header);
	TypeReader<rpg::Database>::WriteLcf(db, writer);
	return true;
}

bool LDB_Reader::SaveXml(std::ostream& filestream, const lcf::rpg::Database& db) {
	XmlWriter writer(filestream, db.system.ldb_id == 2003);
	if (!writer.IsOk()) {
		LcfReader::SetError("Couldn't parse database file.\n");
		return false;
	}
	writer.BeginElement("LDB");
	TypeReader<rpg::Database>::WriteXml(db, writer);
	writer.EndElement("LDB");
	return true;
}

std::unique_ptr<lcf::rpg::Database> LDB_Reader::LoadXml(std::istream& filestream) {
	XmlReader reader(filestream);
	if (!reader.IsOk()) {
		LcfReader::SetError("Couldn't parse database file.\n");
		return nullptr;;
	}
	auto db = std::make_unique<lcf::rpg::Database>();
	reader.SetHandler(new RootXmlHandler<rpg::Database>(*db, "LDB"));
	reader.Parse();

	// Delayed initialization of some actor fields because they are engine
	// dependent
	for (auto& actor: db->actors) {
		actor.Setup(db->system.ldb_id == 2003);
	}

	return db;
}

} // namespace lcf
