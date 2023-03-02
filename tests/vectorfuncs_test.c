#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "vector_funcs.h"

START_TEST(t_vec_add) {
    Vector2 a = {1, 2};
    Vector2 b = {2, 1};
    Vector2* y = Add1(&a, &b);
    ck_assert(y->x == 3 && y->y == 3);
    free(y);
}
END_TEST

START_TEST(t_vec_add_2) {
    Vector2 a = {1, 2};
    Vector2 b = {2, 1};
    Vector2 y = Add2(&a, &b);
    ck_assert(y.x == 3 && y.y == 3);
}
END_TEST

START_TEST(t_vec_sub) {
    Vector2 a = {1, 2};
    Vector2 b = {2, 1};
    Vector2 y = Subtract(&a, &b);
    ck_assert(y.x == -1 && y.y == 1);
}
END_TEST

Suite* CreateSuite() {
    Suite* s = suite_create("Suite");
    TCase* tc = tcase_create("TCore");

    tcase_add_test(tc, t_vec_add);
    tcase_add_test(tc, t_vec_add_2);
    tcase_add_test(tc, t_vec_sub);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int number_failed;
    Suite* s = CreateSuite();
    SRunner* r = srunner_create(s);

    srunner_run_all(r, CK_MINIMAL);
    number_failed = srunner_ntests_failed(r);
    srunner_free(r);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
