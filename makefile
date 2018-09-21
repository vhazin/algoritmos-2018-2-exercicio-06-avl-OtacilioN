#Usage:
# * From linux prompt:
#    - Normal C program (program.c)
#        $ make program.x
# * From vim command:
#    - Normal C program (program.c)
#        :make
# Define DEBUG:
#   $ make program.x DBG=1
#   -B force update


.PHONY: clean
.PRECIOUS: %.o
SHELL=/bin/bash -o pipefail

SET_DEBUG ?= 0
MAX_ITERATION ?= 1000
DO_GIF ?= 0
MAJOR = 0
MINOR = 1
DEFSYM = $(subst .,_,$(BUILD))
VERSION = "\"$(MAJOR).$(MINOR).$(BUILD)\""
CC = gcc
CFLAGS = -Wall -Wextra -g -O0
#-pedantic-errors
#-ansi
CPPFLAGS = -DVERSION=$(VERSION) -DBUILD="\"$(BUILD)\"" -DDEBUG=$(SET_DEBUG) -DITER=$(MAX_ITERATION) -DGIF=$(DO_GIF)

%.x : %.c $(obj)
	$(CC) $(CFLAGS) $(CPPFLAGS)  $^ -o $@ 2>&1 | tee errors.err

%.bfx : %.bf
	    bf $^ -o $@ -i on -p both -r on -w on

clean:
	rm -f *.x errors.err
