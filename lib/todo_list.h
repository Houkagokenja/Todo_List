/* todo_list.h*/
#ifndef  __TODO_LIST_H
#define __TODO_LIST_H

extern int funtion_init_todo_list();
extern int funtion_todo_list_main();
extern int funtion_todo_list_save();

#define SAVE_CHK_LIST   0x00
#define SAVE_CHK_

enum main_list {
    USER_ADD = 1,
    LIST_CHECK,
    EXIT,

    MENU_MAX
};

#endif