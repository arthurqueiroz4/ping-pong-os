#include "queue.h"
#include <stdio.h>

int queue_size(queue_t *queue) {
  if (queue == NULL) {
    return 0;
  }

  queue_t *current = queue;
  int count = 0;

  while (1) {
    count++;
    current = current->next;
    if (current == queue || current == NULL)
      break;
  }

  return count;
}

void queue_print(char *name, queue_t *queue, void (*print_elem)(void *)) {
  if (queue == NULL) {
    printf("%s []\n", name);
    return;
  }
  printf("%s[", name);

  queue_t *current = queue;

  while (1) {
    print_elem(current);
    current = current->next;
    if (current == queue || current == NULL)
      break;
    printf(" ");
  }
  printf("]\n");
}

int queue_append(queue_t **queue, queue_t *elem) {
  if (queue == NULL)
    return -1;

  if (elem == NULL)
    return -1;

  if (elem->next != NULL || elem->prev != NULL)
    return -1;

  // Queue empty
  if (*queue == NULL) {
    *queue = elem;
    elem->next = elem;
    elem->prev = elem;
    return 0;
  }

  queue_t *last = (*queue)->prev;

  elem->next = *queue;
  elem->prev = last;

  (*queue)->prev = elem;
  last->next = elem;

  return 0;
}

int queue_remove(queue_t **queue, queue_t *elem) {
  if (queue == NULL || *queue == NULL)
    return -1;

  if (elem == NULL)
    return -1;

  queue_t *current = *queue;
  int contains = 0;

  while (1) {
    if (current == elem) {
      contains = 1;
      break;
    }
    current = current->next;
    if (current == *queue || current == NULL)
      break;
  }

  if (!contains)
    return -1;

  if (current == *queue) {
    if (current->next == current)
      *queue = NULL;
    else
      *queue = current->next;
  }

  current->prev->next = current->next;
  current->next->prev = current->prev;

  current->next = NULL;
  current->prev = NULL;

  return 0;
}
