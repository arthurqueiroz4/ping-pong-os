#include "ppos.h"
#include <stdio.h>
#include <ucontext.h>

ucontext_t ContextMain;

/*
 * TODO: Preciso ter um task principal?
 */
void ppos_init() {
  setvbuf(stdout, 0, _IONBF, 0);
  getcontext(&ContextMain);
}

/*
 * TODO: Para criar uma task eu preciso:
 *    - setar prev e next;
 *    - criar contexto e anexar na task;
 *    - criar um
 */
int task_init(task_t *task, void (*start_func)(void *), void *arg) {}

int task_switch(task_t *task) {}

void task_exit(int exit_code) {}

int task_id() {}
