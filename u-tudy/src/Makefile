CC = gcc
LIBDIR = ../lib/json-c-build
CFLAGS = -I$(LIBDIR)
LDFLAGS = -L$(LIBDIR)
TARGET = json

all : $(TARGET)

$(TARGET): json.o
	$(CC) -o $(TARGET) json.o $(LIBDIR)/libjson-c.a

main.o : json.c
	$(CC) -c json.c $(CFLAGS)

clean : rm -f *.o $(TARGET)

