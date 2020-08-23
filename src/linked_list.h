#ifndef yacdslib_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

node_t* create_node(int val);
void push(node_t* head, int val);
node_t* create_list_from_array(int arr[], size_t arr_size);

#define yacdslib_LINKED_LIST_H
#endif //yacdslib_LINKED_LIST_H
