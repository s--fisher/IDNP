# IDNP Makefile

CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = -L./sf_library -lsf -lm -L./idnp/tghc -ltghc -lball
EXECUTABLE = idnp
OBJECTS = idnp.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
    $(CC) $(CFLAGS) -c $<

idnp.o: idnp.c idnp.h
clean:
    rm -f $(EXECUTABLE) $(OBJECTS)