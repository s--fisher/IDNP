# IDNP Makefile

CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = -lballa -lball1
EXECUTABLE = idnp
OBJECTS = idnp.o tghc.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

idnp.o: idnp.c idnp.h balla.h ball1.h
tghc.o: tghc.c tghc.h idnp.h

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
