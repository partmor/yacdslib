/**
 * @file linked_list.h
 * @author Pedro Arturo Morales Maries
 * @brief A simple implementation of a singly linked list of integers.
 */

#ifndef YACDSLIB_LINKED_LIST_H

typedef struct node {
    int val;
    struct node* next;
} node_t;

/**
 * @struct list_t
 * The singly linked list struct.
 *
 * @var list_t::head
 *   @brief Pointer to the head ::node_t of the list.
 *
 * @var list_t::tail_sentinel
 *   @brief Sentinel node. Its purpose is to determine the end of the list.
 *
 * @var list_t::number_of_elements
 *   @brief Keeps track of the number of elements in the list at any given time.
 */
typedef struct {
    node_t* head;
    node_t* tail_sentinel;
    int number_of_elements;
} list_t;

/**
 * @brief Initialize empty list.
 *
 * - Sets the head to NULL.
 * - Sets the tail sentinel.
 * - Sets the number of elements to zero.
 *
 * @param list_ptr Pointer to a ::list_t.
 */
void list_init(list_t* list_ptr);

/**
 * @brief Add an item to the end of the list.
 *
 * @param list_ptr Pointer to the ::list_t to be updated.
 * @param val Value to be added to the list.
 */
void list_append(list_t* list_ptr, int val);
void list_init_from_array(list_t* list_ptr, int *arr, size_t arr_size);
void list_prepend(list_t* list_ptr, int val);
int list_get_element(list_t list, size_t loc);
void list_free_memory(list_t* list_ptr);
size_t list_get_size(list_t list);

#define YACDSLIB_LINKED_LIST_H
#endif //YACDSLIB_LINKED_LIST_H
