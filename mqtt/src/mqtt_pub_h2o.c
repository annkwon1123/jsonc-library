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
#define CLIENT_ID_PUB "publisher_client"


// 브로커 연결 시 호출되는 콜백 함수
void on_connect(struct mosquitto *mosq, void *obj, int rc)
{
    if (rc == 0)
    {
        printf("[%s] Connected to MQTT broker at %s:%d.\n", CLIENT_ID_PUB, BROKER_ADDRESS, BROKER_PORT);
    }
    else
    {
        fprintf(stderr, "[%s] Connection failed: %s\n", CLIENT_ID_PUB, mosquitto_strerror(rc));
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        exit(1);
    }
}

// 브로커 연결 해제 시 호출되는 콜백 함수
void on_disconnect(struct mosquitto *mosq, void *obj, int rc)
{
    printf("[%s] Disconnected from MQTT broker (RC: %d).\n", CLIENT_ID_PUB, rc);
}

// 메시지 발행 완료 시 호출되는 콜백 함수
void on_publish(struct mosquitto *mosq, void *obj, int mid)
{
    printf("[%s] Message with mid %d has been published.\n", CLIENT_ID_PUB, mid);
}

// Mosquitto 라이브러리 내부 로그 발생 시 호출되는 콜백 함수
void on_log(struct mosquitto *mosq, void *obj, int level, const char *str)
{
    printf("[%s] Log: %s\n", CLIENT_ID_PUB, str);
}

int main()
{
    struct mosquitto *mosq = NULL;
    int rc;
    char payload[1024];

    // Mosquitto 라이브러리 초기화
    mosquitto_lib_init();

    // 새 Mosquitto 클라이언트 인스턴스 생성
    //   id (const char*): 사용할 클라이언트 ID. NULL이면 랜덤 ID가 생성됨.
    //                     이 ID는 브로커에 연결된 모든 클라이언트 중에서 고유해야 함.
    //   clean_session (bool): true로 설정하면 새로운 세션을 시작하고 (이전 세션 상태 버림, 모든 토픽 구독 해제),
    //                         false로 설정하면 브로커에 ID가 알려진 경우 영구 세션을 재개함.
    //   obj (void*): NULL 고정 권장.
    mosq = mosquitto_new(CLIENT_ID_PUB, true, NULL);
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

    // 메시지 발행이 완료되었을 때 호출될 콜백 설정 (QoS 0은 보통 즉시 호출됨)
    mosquitto_publish_callback_set(mosq, on_publish);

    // Mosquitto 라이브러리 내부 로그 메시지 발생 시 호출될 콜백 설정
    mosquitto_log_callback_set(mosq, on_log);

    // MQTT 브로커에 연결
    //   mosq (struct mosquitto*): Mosquitto 클라이언트 인스턴스.
    //   host (const char*): MQTT 브로커의 IP 주소 또는 호스트 이름.
    //   port (int): MQTT 브로커의 네트워크 포트 (예: 표준 MQTT의 경우 1883, MQTTS의 경우 8883).
    //   keepalive (int): 메시지를 보내거나 받는 최대 주기(초).
    //                    연결을 유지하기 위해 클라이언트가 브로커로 PINGREQ를 보내는 빈도를 정의함.
    rc = mosquitto_connect(mosq, BROKER_ADDRESS, BROKER_PORT, 60); // Keepalive 60초 설정
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "[%s] Initial connection failed: %s\n", CLIENT_ID_PUB, mosquitto_strerror(rc));
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

	sprintf(payload, "This is sample message from publisher...");
    printf("[%s] Attempting to publish '%s' to topic '%s' (QoS: %d)\n", CLIENT_ID_PUB, TOPIC_NAME, payload, QOS_LEVEL);

    // MQTT 메시지 발송
    // 파라미터:
    //   mosq (struct mosquitto*): Mosquitto 클라이언트 인스턴스.
    //   mid (int*): 메시지 ID가 저장될 int 포인터. 필요 없으면 NULL일 수 있음.
    //   topic (const char*): 발행할 MQTT 토픽.
    //   payloadlen (int): 페이로드의 길이(바이트).
    //   payload (const void*): 메시지 페이로드 데이터.
    //   qos (int): 서비스 품질(QoS) 레벨 (0, 1 또는 2).
    //              QoS 0: 최대 한 번 전달.
    //              QoS 1: 최소 한 번 전달.
    //              QoS 2: 정확히 한 번 전달.
    //   retain (bool): 메시지를 브로커에 보존할지 여부. 보존된 메시지는 새로운 구독자에게
    //                  구독 즉시 전달됨.
    rc = mosquitto_publish(mosq, NULL, TOPIC_NAME, strlen(payload), payload, QOS_LEVEL, false);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "[%s] Error publishing message: %s\n", CLIENT_ID_PUB, mosquitto_strerror(rc));
    }

    // 브로커에서 연결 해제
    mosquitto_disconnect(mosq);

    // Mosquitto 리소스 정리
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    printf("[%s] Publish finished.\n", CLIENT_ID_PUB);
    return 0;
}