#include <stdio.h>
#include <string.h>
#include <mosquitto.h>

void message_callback(struct mosquitto *mosq, void *userdata,
		const struct mosquitto_message *msg)
{
	printf("Received message: %s\n", (char *)msg->payload);
}

int main()
{
	if ( mosquitto_lib_init() != MOSQ_ERR_SUCCESS )
	{
		fprintf(stderr, "[ERROR] mosquitto_lib_init");
	}

	struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
	if ( !mosq ) 
	{
		fprintf(stderr, "Failed to create mosquitto object\n");
		return 1;
	}

	mosquitto_message_callback_set(mosq, message_callback);
	
	int erro;
	erro = mosquitto_connect(mosq, "192.168.70.196", 1883, 60);
	if( erro != MOSQ_ERR_SUCCESS )
	{
		fprintf(stderr, "[ERROR] mosquitto_connect --> %d\n", erro);
	}
	
	erro = mosquitto_subscribe(mosq, NULL, "test/topic", 0);
	if( erro != MOSQ_ERR_SUCCESS )
	{
		fprintf(stderr, "[ERROR] mosquitto_subscribe --> %d\n", erro);
	}

	// 메인 루프에서 1개의 메시지 받을 때까지 대기
	mosquitto_loop_forever(mosq, -1, 1);

	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}

