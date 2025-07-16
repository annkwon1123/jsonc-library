#include <stdio.h>
#include <mosquitto.h>

int main() 
{
	mosquitto_lib_init();

	struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
	if ( !mosq )
	{
		fprintf(stderr, "Falied to create mosquitto object\n");
		return 1;
	}

	mosquitto_connect(mosq, "192.168.71.172", 1883, 60);

	mosquitto_publish(mosq, NULL, "test/topic", 12, "Hello MQTT!", 0, false);
	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
