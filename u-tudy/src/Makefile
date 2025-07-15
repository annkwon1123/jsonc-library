CC = gcc
LIBDIR = /home/project/u-tudy/lib/json-c-build
CFLAGS = -I$(LIBDIR)
LDFLAGS = -L$(LIBDIR)
TARGET = myprog

all : $(TARGET)

$(TARGET): json.o
	$(CC) -o $(TARGET) json.o $(LDFLAGS) -ljson-c

main.o : json.c
	$(CC) -c json.c $(CFLAGS)

clean : rm -f *.o $(TARGET)

