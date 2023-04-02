C=gcc
CC=g++
CFLAGS=-pthread -g

Make: 
	$(C) ${CFLAGS} -o proj2a proj2a.c
	$(CC) ${CFLAGS} -o proj2b proj2b.cpp
	$(CC) ${CFLAGS} -o proj2c proj2c.cpp


proj2a:
	$(C) ${CFLAGS} -o proj2a proj2a.cpp

proj2b:
	$(CC) ${CFLAGS} -o proj2b proj2b.cpp

proj2c:
	$(CC) ${CFLAGS} -o proj2c proj2c.cpp

clean: 
	rm -f proj2a proj2b


all: Make 
all: clean 
all: run
all: proj2a 
all: proj2b
