#ifndef yacdslib_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

node_t* create_node(int val);
void push(node_t* head, int val);

#define yacdslib_LINKED_LIST_H
#endif //yacdslib_LINKED_LIST_H
