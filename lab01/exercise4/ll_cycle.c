// Copyright 2023 Muhammad Hayat
#include <stdio.h>
#include <stddef.h>
#include "/home/hayat/C_programming/su21-lab-starter/lab01/exercise4/ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    node *fast_ptr = head;
    node  *slow_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL && fast_ptr->next->next != NULL) {
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
    if (fast_ptr == slow_ptr) {
        return 1;
    }
    if (fast_ptr == NULL && fast_ptr->next->next == NULL) {
        return 1;
  }
  }
  return 0;
    }
