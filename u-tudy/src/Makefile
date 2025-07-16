CC = gcc

JSONDIR = $(PROJ_PATH)/u-tudy
LIBDIR = $(JSONDIR)/lib/json-c-build
BINDIR = $(JSONDIR)/bin

CFLAGS = -I$(LIBDIR)
LDFLAGS = -L$(LIBDIR) $(LIBDIR)/libjson-c.a
TARGET = json

all : $(TARGET)

$(TARGET): json.o
	$(CC) -o $(TARGET) $^ $(LDFLAGS)
	mv $(TARGET) $(BINDIR)

main.o : json.c
	$(CC) -c $< $(CFLAGS)

$(BINDIR) :
	mkdir -p $(BINDIR)

clean : 
	rm -f *.o $(TARGET)

