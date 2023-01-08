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

#ifndef HOOI_SV_H_
#define HOOI_SV_H_

#include <stddef.h>

typedef struct {
  size_t len;
  const char *str;
} StringView;

typedef enum {
  SV_LEFT = 1 << 0,
  SV_RIGHT = 1 << 1,
} SVSide;

#define SV_NULL    ((StringView){0})
#define SV_FMT     "%.*s"
#define SV_ARG(SV) (int)(SV).len, (SV).str

/* Create StringView from STR. */
extern StringView sv_create(const char *str);
/* Trim spaces from SV from sides given in MASK. */
extern StringView sv_trim(StringView sv, SVSide mask);
/* Remove N characters from MASK side of SV (only 1 side may be given).
 * Return removed characters as StringView. */
extern StringView sv_chop(StringView *sv, size_t n, SVSide mask);
/* Checks if SV1 and SV2 are equal. */
extern int sv_eq(StringView sv1, StringView sv2);

#endif /* HOOI_SV_H_ */
