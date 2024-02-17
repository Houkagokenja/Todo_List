#ifndef __MAIN_H
#define __MAIN_H

#define TODO_LIST_IDLE      0x01
#define TODO_LIST_MAIN      0x02
#define TODO_LIST_INIT      0x03
#define TODO_LIST_DELETE    0x04
#define TODO_LIST_CHECK     0x05
#define TODO_LIST_END       0x06

typedef struct todo_list_info {
    char name[20];
    char date[20];

    int status;
    char todo_list;
}TODO_LIST_INFO;

extern int main();
#endif