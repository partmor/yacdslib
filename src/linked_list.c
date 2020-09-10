#include <stdlib.h>
#include "linked_list.h"

void list_node_init(node_t** node, int val, node_t* next){
    (*node) = malloc(sizeof(node_t));
    (*node)->val = val;
    (*node)->next = next;
}

void list_init(list_t* list_ptr){
    list_ptr->head = NULL;
    list_ptr->tail_sentinel = NULL;
    list_ptr->number_of_elements = 0;
}

void list_append_to_empty_list(list_t *list_ptr, int val) {
    list_node_init(&list_ptr->head, val, list_ptr->tail_sentinel);
    list_ptr->number_of_elements++;
}

void list_append_to_populated_list(list_t *list_ptr, int val) {
    // navigate to last node:
    node_t* node = list_ptr->head;
    while(node->next != list_ptr->tail_sentinel){
        node = node->next;
    }
    // create the link:
    node_t* new_node;
    list_node_init(&new_node, val, list_ptr->tail_sentinel);
    node->next = new_node;
    list_ptr->number_of_elements++;
}

void list_append(list_t* list_ptr, int val){
    if(!list_ptr->head){
        list_append_to_empty_list(list_ptr, val);
    } else{
        list_append_to_populated_list(list_ptr, val);
    }
}

int list_get_element(list_t list, size_t loc){
    node_t* node = list.head;
    for(size_t count = 1; count <= loc; ++count){
        node = node->next;
    }
    return node->val;
}

void list_init_from_array(list_t* list_ptr, int *arr, size_t arr_size){
    list_init(list_ptr);
    for(size_t ix = 0; ix < arr_size; ++ix){
        list_append(list_ptr, arr[ix]);
    }
}

void list_prepend(list_t* list_ptr, int val){
    node_t* new_node;
    list_node_init(&new_node, val, list_ptr->head);
    list_ptr->head = new_node;
}

void list_free_memory(list_t* list_ptr){
    node_t* node = list_ptr->head;
    // free all nodes of the list
    while(node != list_ptr->tail_sentinel){
        node_t* node_to_delete = node;
        node = node->next;
        free(node_to_delete);
    }
    // finally, zero-initialize the list
    list_init(list_ptr);
}

size_t list_get_size(list_t list){
    // should be equal to list.number_of_elements
    size_t count = 0;
    node_t* node = list.head;
    while(node != list.tail_sentinel){
        node = node->next;
        ++count;
    }
    return count;
}
