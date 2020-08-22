#include <stdlib.h>
#include "linked_list.h"


node_t* create_head(int val){
    node_t* head = malloc(sizeof(node_t));
    head->val = val;
    head->next = NULL;
    return head;
}