#ifndef YACDSLIB_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

typedef struct list {
    node_t* head;
    node_t* tail_sentinel;

    int number_of_elements;
} list_t;

void list_init(list_t* list_ptr);
void list_append(list_t* list_ptr, int val);
void list_init_from_array(list_t* list_ptr, int *arr, size_t arr_size);
void list_prepend(list_t* list_ptr, int val);
int list_get_element(list_t list, size_t loc);
void list_free_memory(list_t* list_ptr);
size_t list_get_size(list_t list);

#define YACDSLIB_LINKED_LIST_H
#endif //YACDSLIB_LINKED_LIST_H
