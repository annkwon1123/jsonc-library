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
    struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
    if(!mosq) {
        fprintf(stderr, "Failed to create mosquitto object\n");
        return 1;
    }

    mosquitto_message_callback_set(mosq, message_callback);
    mosquitto_connect(mosq, "localhost", 1883, 60);
    mosquitto_subscribe(mosq, NULL, "test/topic", 0);

    // 메인 루프에서 1개의 메시지 받을 때까지 대기
    mosquitto_loop_forever(mosq, -1, 1);

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    return 0;
}

