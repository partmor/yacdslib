#include <stdlib.h>
#include "test_vector.h"
#include "../src/vector.h"

START_TEST(test_create_empty_vector){
    vector_t v = create_empty_vector(5);
    ck_assert_ptr_nonnull(v.array);
}
END_TEST


Suite* make_vector_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("vector");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_empty_vector);

    suite_add_tcase(s, tc_core);

    return s;
}
