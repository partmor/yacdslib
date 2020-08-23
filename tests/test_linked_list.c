#include <stdlib.h>
#include <check.h>
#include "../src/linked_list.h"

START_TEST(test_create_node){
    node_t* head = create_node(1);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(head->val, 1);
    ck_assert_ptr_null(head->next);
}
END_TEST

START_TEST(test_push_back){
    /* Create a 3-node list: 1 -> 2 -> 3 */
    node_t* head = create_node(1);
    push_back(head, 2);
    push_back(head, 3);

    /* Traverse the list and finally check the last node point's next
     * points to NULL */
    node_t* node = head;
    for(size_t i = 1; i <= 3; ++i){
        ck_assert_int_eq(node->val, i);
        node = node->next;
    }
    ck_assert_ptr_null(node);
}
END_TEST

START_TEST(test_create_from_array){
    /* Create a 3-node list: 1 -> 2 -> 3 */
    int arr[3] = {1, 2, 3};
    node_t* head = create_list_from_array(arr, 3);

    /* Traverse the list and finally check the last node point's next
     * points to NULL */
    node_t* node = head;
    for(size_t i = 1; i <= 3; ++i){
        ck_assert_int_eq(node->val, i);
        node = node->next;
    }
    ck_assert_ptr_null(node);
}
END_TEST

START_TEST(test_push_front){
    /* Create a 3-node list: 1 -> 2 -> 3 */
    int arr[3] = {1, 2, 3};
    node_t* head = create_list_from_array(arr, 3);

    /* Push a node to the front and retrieve new head
     * the sequence should now be 0 -> 1 -> 2 -> 3 */
    head = push_front(head, 0);

    /* Traverse the list and finally check the last node point's next
     * points to NULL */
    node_t* node = head;
    for(size_t i = 0; i <= 3; ++i){
        ck_assert_int_eq(node->val, i);
        node = node->next;
    }
    ck_assert_ptr_null(node);
}
END_TEST

Suite* make_linked_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("linked_list");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_node);
    tcase_add_test(tc_core, test_push_back);
    tcase_add_test(tc_core, test_create_from_array);
    tcase_add_test(tc_core, test_push_front);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = make_linked_list_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
