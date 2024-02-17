#include "common.h"
#define MEMBER_DATA_TMP "/home/tarpas/tarpas/Todo_list/tmp/member_data"

int funtion_init_todo_list(TODO_LIST_INFO *cli) {
    return 0;
}

int funtion_todo_list_main(TODO_LIST_INFO *cli) {
    int sel_menu = 0;
    printf("메뉴를 선택해주세요.\n");
    printf("=============================\n");
    printf("1. 사용자 추가하기\n");
    printf("2. 할 일 확인\n");
    printf("3. 종료하기\n");
    printf("=============================\n");
    scanf("%d", &sel_menu);
    
    switch (sel_menu) {
        case USER_ADD:
            cli->status = TODO_LIST_INIT;
            break;

        case LIST_CHECK:
            cli->status = TODO_LIST_INIT;
            break;

        case EXIT:
            cli->status = TODO_LIST_END;
            break;

        default:
            printf("해당 메뉴는 존재하지 않습니다.\n");
            break;
    }
    return 1;
}

static int todo_list_save_start(TODO_LIST_INFO *cli) {
    FILE* fp;
    int run_save = 1;
    int count = 0;

    fp = fopen(MEMBER_DATA_TMP, "wt");

    if(fp) {
        while(run_save)
        {
            printf("+");
            count++;

            switch(count)
            {
                case 0:
                {
                    fopen(MEMBER_DATA_TMP, "r");
                }break;
                case 25:
                {
                    fprintf(fp, "%s\n", cli->name);
                    fprintf(fp, "%s\n", cli->date);
                }break;
                case 50:
                {

                }break;
                case 75:
                {

                }break;
                case 100:
                {
                    run_save = 0;
                    printf("\n");
                    printf("[저장완료]\n");
                }break;
            }
        }
    }
    fclose(fp);
    cli->status = TODO_LIST_MAIN;
    printf("메인메뉴로 돌아갑니다.\n");

    return 0;
}

int funtion_todo_list_save(TODO_LIST_INFO *cli) {
    char save_chk[32] = {0, };

    printf("해당 내용을 저장하시겠습니까?");
    printf("__________________________(YES) / (NO)\n");
    printf("이름 : %s\n",cli->name);
    printf("날짜 : %s\n",cli->date);
    scanf("%s",save_chk);

    if ( strcasecmp(save_chk, "YES") == 0 ) {
        printf("저장 중 입니다...\n");
        todo_list_save_start(cli);
        return 0;

    } else if ( strcasecmp(save_chk, "NO") == 0 ) {
        printf("메뉴로 돌아갑니다.\n");
        return 0;
    } else {
        printf("다시 입력해주세요.");
        return 1;
    }

    return 1;
}