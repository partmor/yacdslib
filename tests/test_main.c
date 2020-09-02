#include <check.h>
#include <stdlib.h>
#include "test_linked_list.h"
#include "test_vector.h"

int run_suite(Suite *s)
{
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int failed_count = srunner_ntests_failed(sr);
    srunner_free(sr);
    return failed_count;
}


int main(void){
    int failed_count = 0;

    failed_count += run_suite(make_linked_list_suite());
    failed_count += run_suite(make_vector_suite());

    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}