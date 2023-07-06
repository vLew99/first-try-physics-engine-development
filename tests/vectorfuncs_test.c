#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "vector_funcs.h"

START_TEST(t_vec_add) {
    Vector2 a = {1, 2};
    Vector2 b = {2, -3};
    Vector2 y = AddV2(a, b);
    ck_assert(y.x == 3 && y.y == -1);
}
END_TEST

START_TEST(t_vec_sub) {
    Vector2 a = {1, 2};
    Vector2 b = {2, 1};
    Vector2 y1 = SubV2(a, b);
    Vector2 y2 = SubV2(b, a);
    ck_assert(y1.x == -1 && y1.y == 1);
    ck_assert(y2.x == 1 && y2.y == -1);
}
END_TEST

START_TEST(t_vec_equal) {
    Vector2 a = {1, 2};
    Vector2 b = {2, 1};
    bool res = EqualV2(a, b);
    ck_assert(res == false);
}
END_TEST

START_TEST(t_vec3_equal) {
    Vector3 a = {.x = 10, .y = 20, .z = 19};
    Vector3 b = {.x = 54, .y = 34, .z = 109};
    Vector3 c = {.x = 54.0f, .y = 34.0f, .z = 109.000f};
    ck_assert(EqualV3(a, b) == false);
    ck_assert(EqualV3(b, c) == true);
}
END_TEST

START_TEST(t_vec_magnitude) {
    Vector2 a = {1.65, 3.72};
    ck_assert_double_eq(LenV2(a), 4.0695085f);
    ck_assert_double_eq(LenV2(a), 4.06950857f);
}
END_TEST

START_TEST(t_vec_normal) {
    Vector2 a = {10, 40};
    Vector2 normal = NormV2(a);
    Vector2 cmp =
        (Vector2){.x = 0.24253562503633297352f, .y = 0.97014250014533189408f};
    /* ck_assert_double_eq(normal.x, 0.24253562503633297352); */
    /* ck_assert_double_eq(normal.y, 0.97014250014533189408f); */
    ck_assert(EqualV2(normal, cmp));
}
END_TEST

// TODO: t_vec_dot

// TODO: t_vec_cross

Suite* CreateSuite() {
    Suite* s = suite_create("Suite");
    TCase* tc = tcase_create("TCore");

    tcase_add_test(tc, t_vec_equal);
    tcase_add_test(tc, t_vec3_equal);
    tcase_add_test(tc, t_vec_add);
    tcase_add_test(tc, t_vec_sub);
    tcase_add_test(tc, t_vec_magnitude);
    tcase_add_test(tc, t_vec_normal);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int number_failed;
    Suite* s = CreateSuite();
    SRunner* r = srunner_create(s);

    srunner_run_all(r, CK_NORMAL);
    number_failed = srunner_ntests_failed(r);
    srunner_free(r);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
