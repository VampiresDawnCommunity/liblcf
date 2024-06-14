/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_RPG_SAVEEASYRPGDATA_H
#define LCF_RPG_SAVEEASYRPGDATA_H

// Headers
#include <stdint.h>
#include <vector>
#include "lcf/dbstring.h"
#include "lcf/rpg/saveeasyrpgwindow.h"
#include "lcf/context.h"
#include <ostream>
#include <type_traits>

/**
 * rpg::SaveEasyRpgData class.
 */
namespace lcf {
namespace rpg {
	class SaveEasyRpgData {
	public:
		// Sentinel name used to denote that the default language is used for a savegame.
		static constexpr const char* kDefaultLanguage = "default";

		int32_t version = 0;
		int32_t codepage = 0;
		DBString language = DBString(kDefaultLanguage);
		std::vector<SaveEasyRpgWindow> windows;
	};

	inline bool operator==(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return l.version == r.version
		&& l.codepage == r.codepage
		&& l.language == r.language
		&& l.windows == r.windows;
	}

	inline bool operator!=(const SaveEasyRpgData& l, const SaveEasyRpgData& r) {
		return !(l == r);
	}

	std::ostream& operator<<(std::ostream& os, const SaveEasyRpgData& obj);

	template <typename F, typename ParentCtx = Context<void,void>>
	void ForEachString(SaveEasyRpgData& obj, const F& f, const ParentCtx* parent_ctx = nullptr) {
		const auto ctx3 = Context<SaveEasyRpgData, ParentCtx>{ "language", -1, &obj, parent_ctx };
		f(obj.language, ctx3);
		for (int i = 0; i < static_cast<int>(obj.windows.size()); ++i) {
			const auto ctx4 = Context<SaveEasyRpgData, ParentCtx>{ "windows", i, &obj, parent_ctx };
			ForEachString(obj.windows[i], f, &ctx4);
		}
		(void)obj;
		(void)f;
		(void)parent_ctx;
	}

} // namespace rpg
} // namespace lcf

#endif
