#TUTORIAL http://mrbook.org/tutorials/make/
CC=g++
CFLAGMAKE=-c
CFLAGOBJ=-o
SOURCES=main.cc data.cc linux.cc
OBJS=main.o data.o linux.o
TARGET=syslib

all: $(TARGET)

syslib: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.cc
	$(CC) $(CFLAGMAKE) main.cc

linux.o: linux.cc
	$(CC) $(CFLAGMAKE) linux.cc

data.o: data.cc
	$(CC) $(CFLAGMAKE) data.cc

clean:
	rm -rf *.o syslib
