#ifndef CDS_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

node_t* create_head(int val);

#define CDS_LINKED_LIST_H
#endif //CDS_LINKED_LIST_H
