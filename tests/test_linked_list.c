#include <stdlib.h>
#include "test_linked_list.h"
#include "../src/linked_list.h"


START_TEST(test_list_init){
    list_t list;
    list_init(&list);

    ck_assert_ptr_null(list.head);
    ck_assert_ptr_null(list.tail_sentinel);
    ck_assert_int_eq(list.number_of_elements, 0);
}
END_TEST

START_TEST(test_list_append_to_empty_list){
    list_t list;
    list_init(&list);
    list_append(&list, 10);

    ck_assert_ptr_nonnull(list.head);
    ck_assert_ptr_null(list.tail_sentinel);
    ck_assert_int_eq(list.head->val, 10);
    ck_assert_int_eq(list.number_of_elements, 1);
    ck_assert_ptr_eq(list.head->next, list.tail_sentinel);
}
END_TEST

START_TEST(test_list_append_to_populated_list){
    list_t list;
    list_init(&list);
    list_append(&list, 10);
    list_append(&list, 20);

    ck_assert_ptr_nonnull(list.head);
    ck_assert_ptr_null(list.tail_sentinel);
    ck_assert_int_eq(list.number_of_elements, 2);
    node_t* node = list.head;
    for(size_t i = 1; i <= list.number_of_elements; ++i){
        ck_assert_int_eq(node->val, i * 10);
        node = node->next;
    }
    ck_assert_ptr_eq(node, list.tail_sentinel);
}
END_TEST

START_TEST(test_list_get_element_at_location){
    list_t list;
    list_init(&list);
    list_append(&list, 10);
    list_append(&list, 20);
    list_append(&list, 30);

    ck_assert_int_eq(list_get_element(list, 0), 10);
    ck_assert_int_eq(list_get_element(list, 1), 20);
    ck_assert_int_eq(list_get_element(list, 2), 30);
}
END_TEST

START_TEST(test_create_list_from_array){
    int arr[3] = {10, 20, 30};
    list_t list;
    list_init_from_array(&list, arr, 3);

    node_t* node = list.head;
    for(size_t i = 1; i <= 3; ++i){
        ck_assert_int_eq(node->val, i * 10);
        node = node->next;
    }
    ck_assert_ptr_null(node);
    ck_assert_ptr_eq(node, list.tail_sentinel);
}
END_TEST

START_TEST(test_create_list_prepend){
    int arr[3] = {10, 20, 30};
    list_t list;
    list_init_from_array(&list, arr, 3);

    list_prepend(&list, 100);

    ck_assert_int_eq(list.head->val, 100);
    ck_assert_int_eq(list.head->next->val, 10);
}
END_TEST

START_TEST(test_free_list_memory){
    int arr[3] = {10, 20, 30};
    list_t list;
    list_init_from_array(&list, arr, 3);

    list_free_memory(&list);

    ck_assert_ptr_null(list.head);
    ck_assert_int_eq(list.number_of_elements, 0);
}
END_TEST

START_TEST(test_list_get_size){
    int arr[4] = {10, 20, 30, 40};
    list_t list;
    list_init_from_array(&list, arr, 4);

    ck_assert_int_eq(list_get_size(list), 4);
    ck_assert_int_eq(list_get_size(list), list.number_of_elements);
}
END_TEST


Suite* make_linked_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("linked_list");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_list_init);
    tcase_add_test(tc_core, test_list_append_to_empty_list);
    tcase_add_test(tc_core, test_list_append_to_populated_list);
    tcase_add_test(tc_core, test_list_get_element_at_location);
    tcase_add_test(tc_core, test_create_list_from_array);
    tcase_add_test(tc_core, test_create_list_prepend);
    tcase_add_test(tc_core, test_free_list_memory);
    tcase_add_test(tc_core, test_list_get_size);

    suite_add_tcase(s, tc_core);

    return s;
}
