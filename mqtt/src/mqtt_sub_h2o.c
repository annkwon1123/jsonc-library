#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // sleep 함수 사용 중
#include <stdbool.h>
#include "mosquitto.h"

// 서버 IP
#define BROKER_ADDRESS "127.0.0.1"
// 서버 port
#define BROKER_PORT 1883

// 구독 토픽 이름
#define TOPIC_NAME "SAMPLE_TOPIC"
// QoS 레벨 0~2
#define QOS_LEVEL 0

// 브로커에서 관리할 Client ID
#define CLIENT_ID_SUB "subscriber_client"


// 브로커 연결 시 호출되는 콜백 함수임
void on_connect(struct mosquitto *mosq, void *obj, int rc)
{
    if (rc == 0)
    {
        printf("[%s] Connected to MQTT broker at %s:%d.\n", CLIENT_ID_SUB, BROKER_ADDRESS, BROKER_PORT);
        // 정의된 토픽을 구독 중
        // 파라미터:
        //   mosq (struct mosquitto*): Mosquitto 클라이언트 인스턴스.
        //   mid (int*): 구독 메시지 ID가 저장될 int 포인터. NULL일 수 있음.
        //   topic (const char*): 구독할 토픽 필터 문자열. (예: "sensor/temperature", "home/#")
        //   qos (int): 구독에 적용할 최대 QoS 레벨 (0, 1, 또는 2).
        mosquitto_subscribe(mosq, NULL, TOPIC_NAME, QOS_LEVEL);
        printf("[%s] Subscribed to topic '%s' with QoS %d.\n", CLIENT_ID_SUB, TOPIC_NAME, QOS_LEVEL);
    }
    else
    {
        fprintf(stderr, "[%s] Connection failed: %s\n", CLIENT_ID_SUB, mosquitto_strerror(rc));
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        exit(1);
    }
}

// 브로커 연결 해제 시 호출되는 콜백 함수
void on_disconnect(struct mosquitto *mosq, void *obj, int rc)
{
    printf("[%s] Disconnected from MQTT broker (RC: %d).\n", CLIENT_ID_SUB, rc);
}

// 메시지 수신 시 호출되는 콜백 함수
void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
    printf("\n[%s] Message received:\n", CLIENT_ID_SUB);
    printf("  Topic: '%s'\n", msg->topic);
    printf("  Payload: '%.*s'\n", msg->payloadlen, (char*)msg->payload);
    printf("  QoS: %d\n", msg->qos);
    printf("  Retain flag: %d\n\n", msg->retain);
}

// 구독 확인 응답(SUBACK) 수신 시 호출되는 콜백 함수
void on_subscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos)
{
    int i;
    printf("[%s] Subscription with mid %d acknowledged.\n", CLIENT_ID_SUB, mid);
    for (i = 0; i < qos_count; ++i)
    {
        printf("  Granted QoS for subscription %d: %d\n", i + 1, granted_qos[i]);
    }
}

// Mosquitto 라이브러리 내부 로그 발생 시 호출되는 콜백 함수
void on_log(struct mosquitto *mosq, void *obj, int level, const char *str)
{
    printf("[%s] Log: %s\n", CLIENT_ID_SUB, str);
}

int main()
{
    struct mosquitto *mosq = NULL;
    int rc;

    // Mosquitto 라이브러리 초기화
    mosquitto_lib_init();

    // 새 Mosquitto 클라이언트 인스턴스 생성
    // 파라미터:
    //   id (const char*): 사용할 클라이언트 ID. NULL이면 랜덤 ID가 생성됨.
    //                     이 ID는 브로커에 연결된 모든 클라이언트 중에서 고유해야 함.
    //   clean_session (bool): true로 설정하면 새로운 세션을 시작하고 (이전 세션 상태 버림, 모든 토픽 구독 해제),
    //                         false로 설정하면 브로커에 ID가 알려진 경우 영구 세션을 재개함.
    //   obj (void*): NULL 고정 권장.
    mosq = mosquitto_new(CLIENT_ID_SUB, true, NULL);
    if (!mosq)
    {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    // 콜백 함수 등록

    // 브로커 연결 성공/실패 시 호출될 콜백 설정
    mosquitto_connect_callback_set(mosq, on_connect);

    // 브로커 연결 해제 시 호출될 콜백 설정
    mosquitto_disconnect_callback_set(mosq, on_disconnect);

    // 구독한 토픽에 메시지가 도착했을 때 호출될 콜백 설정
    mosquitto_message_callback_set(mosq, on_message);

    // 구독 요청에 대한 브로커의 응답(SUBACK) 수신 시 호출될 콜백 설정
    mosquitto_subscribe_callback_set(mosq, on_subscribe);

    // Mosquitto 라이브러리 내부 로그 메시지 발생 시 호출될 콜백 설정
    mosquitto_log_callback_set(mosq, on_log);

    // MQTT 브로커에 연결
    // 파라미터:
    //   mosq (struct mosquitto*): Mosquitto 클라이언트 인스턴스.
    //   host (const char*): MQTT 브로커의 IP 주소 또는 호스트 이름.
    //   port (int): MQTT 브로커의 네트워크 포트 (예: 표준 MQTT의 경우 1883, MQTTS의 경우 8883).
    //   keepalive (int): 메시지를 보내거나 받는 최대 주기(초).
    //                    연결을 유지하기 위해 클라이언트가 브로커로 PINGREQ를 보내는 빈도를 정의함.
    rc = mosquitto_connect(mosq, BROKER_ADDRESS, BROKER_PORT, 60); // Keepalive 60초 설정
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "[%s] Initial connection failed: %s\n", CLIENT_ID_SUB, mosquitto_strerror(rc));
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    printf("[%s] MQTT loop started. Waiting for messages...\n", CLIENT_ID_SUB);
    // 이 루프는 프로그램이 종료되거나 mosquitto_loop가 오류를 반환할 때까지 계속됨.
    while (1)
    {
        // 파라미터:
        //   mosq (struct mosquitto*): Mosquitto 클라이언트 인스턴스.
        //   timeout (int): 네트워크 이벤트를 기다릴 최대 시간(밀리초).
        //                  -1은 이벤트가 발생할 때까지 블로킹함.
        //                  0은 논블로킹(즉시 반환)함.
        //                  양수는 해당 밀리초만큼 기다림.
        //   max_packets (int): 이 호출에서 처리할 최대 네트워크 패킷 수. 일반적으로 1로 설정함.
        rc = mosquitto_loop(mosq, -1, 1); // -1: 블로킹, 1: 최대 반복 횟수
        if (rc != MOSQ_ERR_SUCCESS)
        {
            fprintf(stderr, "[%s] Error during loop processing: %s\n", CLIENT_ID_SUB, mosquitto_strerror(rc));
            break;
        }
        sleep(1);
    }

    // Mosquitto 리소스 정리
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    printf("[%s] Program terminated.\n", CLIENT_ID_SUB);
    return 0;
}