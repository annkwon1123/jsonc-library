#include <stdio.h>
#include <mosquitto.h>

int main() 
{
	if( mosquitto_lib_init() != MOSQ_ERR_SUCCESS )
	{
		fprintf(stderr, "[ERROR] mosquitto_lib_init\n");
	}

	struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
	if ( !mosq )
	{
		fprintf(stderr, "[ERROR] mosquitto_new\n");
		return 1;
	}

	if ( mosquitto_connect(mosq, "192.168.71.172", 1883, 60) != MOSQ_ERR_SUCCESS);
	{
		fprintf(stderr, "[ERROR] mosquitto_connect\n");
	}
	int erro;
	erro = mosquitto_publish(mosq, NULL, "test/topic", 12, "Hello MQTT!", 0, false);
	if( erro != MOSQ_ERR_SUCCESS )
	{
		fprintf(stderr, "[ERROR] mosquitto_publish --> %d\n", erro);
	}
	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
