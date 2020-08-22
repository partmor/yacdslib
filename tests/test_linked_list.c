#include <stdlib.h>
#include <check.h>
#include "../src/linked_list.h"

START_TEST(test_create_head){
    node_t* head = create_head(1);
    ck_assert_ptr_nonnull(head);
    ck_assert_int_eq(head->val, 1);
    ck_assert_ptr_null(head->next);
}
END_TEST

Suite* make_linked_list_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("linked_list");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_head);
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
