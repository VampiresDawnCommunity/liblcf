/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) 2020 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

// Headers
#include "lcf/ldb_reader.h"
#include "lcf/ldb_chunks.h"
#include "reader_struct_impl.h"

namespace lcf {

// Read BattleCommands.

template <>
char const* const Struct<rpg::BattleCommands>::name = "BattleCommands";
static TypedField<rpg::BattleCommands, int32_t> static_placement(
	&rpg::BattleCommands::placement,
	LDB_Reader::ChunkBattleCommands::placement,
	"placement",
	0,
	0
);
static TypedField<rpg::BattleCommands, bool> static_death_handler_unused(
	&rpg::BattleCommands::death_handler_unused,
	LDB_Reader::ChunkBattleCommands::death_handler_unused,
	"death_handler_unused",
	0,
	1
);
static TypedField<rpg::BattleCommands, int32_t> static_row(
	&rpg::BattleCommands::row,
	LDB_Reader::ChunkBattleCommands::row,
	"row",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_battle_type(
	&rpg::BattleCommands::battle_type,
	LDB_Reader::ChunkBattleCommands::battle_type,
	"battle_type",
	0,
	0
);
static TypedField<rpg::BattleCommands, bool> static_unused_display_normal_parameters(
	&rpg::BattleCommands::unused_display_normal_parameters,
	LDB_Reader::ChunkBattleCommands::unused_display_normal_parameters,
	"unused_display_normal_parameters",
	0,
	0
);
static TypedField<rpg::BattleCommands, std::vector<rpg::BattleCommand>> static_commands(
	&rpg::BattleCommands::commands,
	LDB_Reader::ChunkBattleCommands::commands,
	"commands",
	1,
	0
);
static TypedField<rpg::BattleCommands, bool> static_death_handler(
	&rpg::BattleCommands::death_handler,
	LDB_Reader::ChunkBattleCommands::death_handler,
	"death_handler",
	0,
	1
);
static TypedField<rpg::BattleCommands, int32_t> static_death_event(
	&rpg::BattleCommands::death_event,
	LDB_Reader::ChunkBattleCommands::death_event,
	"death_event",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_window_size(
	&rpg::BattleCommands::window_size,
	LDB_Reader::ChunkBattleCommands::window_size,
	"window_size",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_transparency(
	&rpg::BattleCommands::transparency,
	LDB_Reader::ChunkBattleCommands::transparency,
	"transparency",
	0,
	0
);
static TypedField<rpg::BattleCommands, bool> static_death_teleport(
	&rpg::BattleCommands::death_teleport,
	LDB_Reader::ChunkBattleCommands::death_teleport,
	"death_teleport",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_death_teleport_id(
	&rpg::BattleCommands::death_teleport_id,
	LDB_Reader::ChunkBattleCommands::death_teleport_id,
	"death_teleport_id",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_death_teleport_x(
	&rpg::BattleCommands::death_teleport_x,
	LDB_Reader::ChunkBattleCommands::death_teleport_x,
	"death_teleport_x",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_death_teleport_y(
	&rpg::BattleCommands::death_teleport_y,
	LDB_Reader::ChunkBattleCommands::death_teleport_y,
	"death_teleport_y",
	0,
	0
);
static TypedField<rpg::BattleCommands, int32_t> static_death_teleport_face(
	&rpg::BattleCommands::death_teleport_face,
	LDB_Reader::ChunkBattleCommands::death_teleport_face,
	"death_teleport_face",
	0,
	0
);


template <>
Field<rpg::BattleCommands> const* Struct<rpg::BattleCommands>::fields[] = {
	&static_placement,
	&static_death_handler_unused,
	&static_row,
	&static_battle_type,
	&static_unused_display_normal_parameters,
	&static_commands,
	&static_death_handler,
	&static_death_event,
	&static_window_size,
	&static_transparency,
	&static_death_teleport,
	&static_death_teleport_id,
	&static_death_teleport_x,
	&static_death_teleport_y,
	&static_death_teleport_face,
	NULL
};

template class Struct<rpg::BattleCommands>;

} //namespace lcf
