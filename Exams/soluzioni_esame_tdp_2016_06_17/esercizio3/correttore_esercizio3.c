#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "correttore_esercizio3.h"

void ground_truth_aux(ListNode* output_list, ListNode* src, int first) {
  if(src == NULL) {
    return;
  }

  ListNode* previous_node = output_list;
  output_list->next = (ListNode*)calloc(1, sizeof(ListNode));
  output_list = output_list->next;
  output_list->next = NULL;
  if(first) {
    output_list->value = src->value;  
  }
  else {
    output_list->value = previous_node->value + src->value;  
  }

  ground_truth_aux(output_list, src->next, 0);
}

ListNode* ground_truth(ListNode* src) {
  ListNode* gen_node = (ListNode*)calloc(1, sizeof(ListNode));
  gen_node->next = NULL;

  ground_truth_aux(gen_node, src, 1);
  
  ListNode* list = gen_node->next;
  free(gen_node);

  return list;
}
