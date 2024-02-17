# TODO LIST MAKEFILE

TOP_DIR = /home/tarpas/tarpas
LIB_DIR = $(TOP_DIR)/lib

gcc -Wall -c /home/tarpas/tarpas/Todo_list/lib/main.c
gcc -Wall -c /home/tarpas/tarpas/Todo_list/lib/todo_list.c

gcc main.o todo_list.o -o program