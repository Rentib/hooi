VERSION = 1.0

CPPFLAGS = -DVERSION=\"$(VERSION)\"
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O0 -ggdb $(CPPFLAGS)
LDFLAGS =
CC = cc

SRC = hooi.c
OBJ = $(SRC:.c=.o)

all: options hooi

options:
	@echo hooi build options:
	@echo "CFLAGS  = $(CFLAGS)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "CC      = $(CC)"

.c.o:
	$(CC) -c $(CFLAGS) $<

$(OBJ):

hooi: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f hooi $(OBJ)
