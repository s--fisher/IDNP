sf_library:
	mkdir $@

sf_library/%.h: %.h | sf_library
	cp $< $@

# IDNP Makefile with RAID 0, RAID 1, and RAID 5
CC = gcc
CFLAGS = -Wall -Werror -g
LIBS = -L./sf_library -lsf -lm
EXECUTABLE = idnp
OBJECTS = idnp.o tghc.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I./sf_library -c $< $(LIBS)

idnp.o: idnp.c idnp.h sf_library/sf.h
	$(CC) $(CFLAGS) -I./ -I./sf_library -c $< $(LIBS)

tghc.o: tghc.c tghc.h sf_library/sf.h
	$(CC) $(CFLAGS) -I./ -I./sf_library -c $< $(LIBS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
	rm client

# Check if IDNP filesystem is mounted, then create RAID 0
raid0:
	if grep -qs '/dev/idnp ' /proc/mounts; \
	then \
	    sudo mdadm --create /dev/idnp-raid0 --level=0 --raid-devices=4 /dev/sf /dev/sdc /dev/sdd /dev/sde; \
	else \
	    echo "IDNP filesystem is not mounted"; \
	    exit 1; \
	fi

# Check if IDNP filesystem is mounted, then create RAID 1
raid1:
	if grep -qs '/dev/idnp ' /proc/mounts; \
	then \
	    sudo mdadm --create /dev/idnp-raid1 --level=1 --raid-devices=2 /dev/sdf /dev/sdg; \
	else \
	    echo "IDNP filesystem is not mounted"; \
	    exit 1; \
	fi

# Check if IDNP filesystem is mounted, then create RAID 5
raid5:
	if grep -qs '/dev/idnp ' /proc/mounts; \
	then \
	    sudo mdadm --create /dev/idnp-raid5 --level=5 --raid-devices=4 /dev/sdh /dev/sdi /dev/sdj /dev/sdk; \
	else \
	    echo "IDNP filesystem is not mounted"; \
	    exit 1; \
	fi

# Create RAID 0 on SATA array
raid0-sata:
	sudo mdadm --create /dev/idnp-raid0-sata --level=0 --raid-devices=2 /dev/sdl /dev/lib

run:
	gcc client.c -o client -lm -Wall
#	__start':
#		> trundle client[%]
#		> tundle ?
#	^C
	if [ ! -f client ]; \
		echo "client ? > "
		./client
	else;
		make install

install:
	clear
	if [ ! -f client ]; \
		then \
			clear; \
			make clean; \
			echo "IDNP online"; \
	fi
	make
	echo "trundle ? > gcc \"@@ -0,0 +1,73 @@\" -o client -"
	make run
	clear

