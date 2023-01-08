/*
  hooi, a chess engine.
  Copyright (C) 2022 Stanisław Bitner <sbitner420@tutanota.com>

  hooi is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  hooi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sv.h"

#include <ctype.h>
#include <string.h>

static StringView sv_trim_left(StringView sv);
static StringView sv_trim_right(StringView sv);

StringView
sv_create(const char *cstr)
{
  return (StringView){.len = strlen(cstr), .str = cstr};
}

StringView
sv_trim_left(StringView sv)
{
  size_t shift = 0;
  while (shift < sv.len && isspace(sv.str[shift])) shift++;
  return (StringView){.len = sv.len - shift, .str = sv.str + shift};
}

StringView
sv_trim_right(StringView sv)
{
  size_t shift = 0;
  while (shift < sv.len && isspace(sv.str[sv.len - shift - 1])) shift++;
  return (StringView){.len = sv.len - shift, .str = sv.str};
}

StringView
sv_trim(StringView sv, SVSide mask)
{
  StringView res = sv;
  if (mask & SV_LEFT) res = sv_trim_left(res);
  if (mask & SV_RIGHT) res = sv_trim_right(res);
  return res;
}

StringView
sv_chop(StringView *sv, size_t n, SVSide mask)
{
  StringView res = (StringView){0};
  if (n > sv->len) n = sv->len;

  switch (mask) {
  case SV_LEFT: {
    res.len = n;
    res.str = sv->str;
    sv->len -= n;
    sv->str += n;
  } break;
  case SV_RIGHT: {
    res.len = n;
    res.str = sv->str + sv->len - n;
    sv->len -= n;
    /* sv->str += 0; */
  } break;
  default:
    break;
  }

  return res;
}

int
sv_cmp(StringView sv1, StringView sv2)
{
  return sv1.len == sv2.len ? !memcmp(sv1.str, sv2.str, sv1.len) : 0;
}
