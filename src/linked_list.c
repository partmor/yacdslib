#include <stdlib.h>
#include "linked_list.h"


node_t* create_node(int val){
    node_t* head = malloc(sizeof(node_t));
    head->val = val;
    head->next = NULL;
    return head;
}

void push_back(node_t* head, int val){
    node_t* node = head;
    while(node->next){
        node = node->next;
    }
    node->next = create_node(val);
}

node_t* push_front(node_t* head, int val){
    node_t* new_head = create_node(val);
    new_head->next = head;
    return new_head;
}

node_t* create_list_from_array(int arr[], size_t arr_size){
    node_t* head = NULL;
    if(arr_size){
        head = create_node(arr[0]);
        for(size_t i = 1; i < arr_size; ++i){
            push_back(head, arr[i]);
        }
    }
    return head;
}

int size(node_t* head){
    int count = 0;
    node_t* node = head;
    while (node){
        node = node->next;
        ++count;
    }
    return count;
}