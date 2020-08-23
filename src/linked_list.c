#include <stdlib.h>
#include "linked_list.h"


node_t* create_node(int val){
    node_t* head = malloc(sizeof(node_t));
    head->val = val;
    head->next = NULL;
    return head;
}

void push(node_t* head, int val){
    node_t* node = head;
    while(node->next){
        node = node->next;
    }
    node->next = create_node(val);
}