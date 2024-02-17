/* TODO LIST */
#include "common.h"
static TODO_LIST_INFO list_data;

static void list_data_cleanup() {
    TODO_LIST_INFO *cli = &list_data;
    memset(cli, 0x00, 1024);
}

static void list_start() {
    printf("[-TODO LIST-]________________________\n");
}

static int list_init(TODO_LIST_INFO *cli) {
    printf("lisr_init_start\n");
    int end_init = 1;
    int name_size = 0;
    int date_size = 0;
    char* buffer;

    /*
    입력받을 내용
    1. 이름
    2. 날짜
    3. 오늘 할 일 {
                    1.
                    2.
                    3. ...
                    완료(END)
                }
    메모장으로 데이터 저장...
    */
   printf("debugf_point_00\n");
    if ( cli->status > 0x00) {
        while(end_init) {
            /* 문자열 길이 체크 */
            name_size = strlen(cli->name);
            date_size = strlen(cli->date);
            printf("name_size : %d\n", name_size);
            printf("date_size : %d\n", date_size);

            buffer = (char*)malloc(sizeof(char) * ( 
                            name_size + 
                            date_size + 1));

            // 이름 입력
            if (name_size == 0 && date_size == 0) {
                printf("이름을 입력하세요 : ");
                scanf("%s",cli->name);
                strcpy(buffer, cli->name);
                printf("name insert buffer : %s\n",buffer);
            } 
            else if (name_size != 0 && date_size == 0) {
                printf("날짜를 입력하세요 : ");
                scanf("%s",cli->date);
                strcpy(buffer, cli->date);

                printf("date insert buffer : %s\n",buffer);
            } 
            else if (name_size != 0 && date_size != 0 ) {
                end_init = funtion_todo_list_save(cli);
                cli->status = TODO_LIST_END;
            } 
            else {
                printf("구현되지 않았습니다.\n");
            }
            free(buffer);
        }
    }
    return 0;
}

static void main_thread() {
    TODO_LIST_INFO *cli = &list_data;
    int ret = 0;
    cli->status = TODO_LIST_MAIN;

    while(1) {
        switch(cli->status) {
            case TODO_LIST_MAIN:
                funtion_todo_list_main(cli);
                cli->status = TODO_LIST_INIT;
                break;
            case TODO_LIST_INIT:
                printf("[메뉴] 사용자 추가하기_________________\n");
                ret = list_init(cli);
                break;
            case TODO_LIST_CHECK:
                printf("[메뉴] 할일 확인_________________\n");
            case TODO_LIST_END:
                printf("종료합니다...\n");
                exit(0);
                break;
            default:
               printf("list status fail\n");
                break;
        }
        printf("alive main thread\n");
        sleep(1);
    }
    printf("ret : %d\n",ret);
}

int main() {
    list_start();           // TODO_LSIT 시작
    list_data_cleanup();    // TODO_LIST 초기화
    main_thread();          // 메인 쓰레드 실행
    return 0;
}