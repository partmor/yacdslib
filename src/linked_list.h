#ifndef yacdslib_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

node_t* create_node(int val);
void push_back(node_t* head, int val);
node_t* push_front(node_t* head, int val);
node_t* create_list_from_array(int arr[], size_t arr_size);
int size(node_t* head);
node_t* get_node(node_t* head, size_t pos);
node_t* peek_last(node_t* head);

#define yacdslib_LINKED_LIST_H
#endif //yacdslib_LINKED_LIST_H
