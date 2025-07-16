CC=gcc

MQTTDIR = $(PROJ_PATH)/mqtt
LIBDIR = $(MQTTDIR)/lib/mosquitto-build/lib
BINDIR = $(MQTTDIR)/bin

CFLAGS = -I$(LIBDIR)
LDFLAGS = -L$(LIBDIR) $(LIBDIR)/libmosquitto.a -lpthread -lssl -lcrypto

TARGETS = mqtt_pub mqtt_sub

all : $(BINDIR) $(TARGETS)

mqtt_pub: mqtt_pub.o
	$(CC) -o $@ $^ $(LDFLAGS)
	mv $@ $(BINDIR)

mqtt_sub: mqtt_sub.o
	$(CC) -o $@ $^ $(LDFLAGS)
	mv $@ $(BINDIR)

mqtt_pub.o : mqtt_pub.c
	$(CC) -c $< $(CFLAGS)

mqtt_sub.o : mqtt_sub.c
	$(CC) -c $< $(CFLAGS)

$(BINDIR) :
	mkdir -p $(BINDIR)

clean : 
	rm -f *.o $(TARGETS)
