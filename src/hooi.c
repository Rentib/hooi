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

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void error(const char *fmt, ...);
static void usage(FILE *stream);
static char *shift(int *argc, char ***argv);

void
error(const char *fmt, ...)
{
  va_list ap;

  fputs("error: ", stderr);
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);

  fputc('\n', stderr);
  exit(1);
}

void
usage(FILE *stream)
{
  fprintf(stream,
          "Usage: hooi [options] file...\n"
          "Options:\n"
          "  -h               Display this information\n"
          "  -o <file>        Write output to <file>\n");
}

char *
shift(int *argc, char ***argv)
{
  assert(*argc > 0);
  char *res = **argv;
  --*argc;
  ++*argv;
  return res;
}

int
main(int argc, char *argv[])
{
  const char *prog = shift(&argc, &argv);
  const char *input = NULL;
  const char *output = NULL;

  (void)prog;
  (void)input;
  (void)output;

  while (argc > 0) {
    const char *flag = shift(&argc, &argv);

    if (!strcmp(flag, "-o")) {
      if (argc <= 0) error("argument to '%s' is missing");
      output = shift(&argc, &argv);
    } else if (!strcmp(flag, "-h")) {
      usage(stderr);
      exit(1);
    } else {
      input = flag;
    }
  }

  if (input == NULL) error("no input files");

  return EXIT_SUCCESS;
}
