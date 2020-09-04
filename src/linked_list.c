#include <stdlib.h>
#include "linked_list.h"


node_t* create_node(int val){
    node_t* head = malloc(sizeof(node_t));
    head->val = val;
    head->next = NULL;
    return head;
}

node_t* peek_last(node_t* head){
    node_t* node = head;
    while (node->next){
        node = node->next;
    }
    return node;
}

void push_back(node_t* head, int val){
    node_t* node = peek_last(head);
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

node_t* get_node(node_t* head, size_t pos){
    node_t* node = head;
    for (size_t i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node;
}

void free_linked_list(node_t* head){
    node_t* node = head;
    node_t* to_free;
    while(node){
        to_free = node;
        node = node->next;
        free(to_free);
        to_free = NULL; // just for peace of mind
    }
}
