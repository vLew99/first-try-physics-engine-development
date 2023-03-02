#include <stdbool.h>
#include <stdio.h>

/*#define _USE_MATH_DEFINES*/
#undef __STRICT_ANSI__

#include <assert.h>
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "collision.h"
#include "dynamics.h"
#include "polygon_funcs.h"
#include "types.h"
#include "vector_funcs.h"

START_TEST(t_point_point_collision) {
    Point2D a = {1.2223, 2.2};
    Point2D b = {1.2223, 2.2};
    Point2D c = {1.2223, 2.3};
    ck_assert(CheckPointPointCollision(&a, &b) == true);
    ck_assert(CheckPointPointCollision(&a, &c) != true);
}
END_TEST

START_TEST(t_point_circle_collision) {
    Point2D a = {1, 2};
    Circle c = {.x = 4, .y = 5, .z = 4.25};
    Circle c2 = {.x = 4, .y = 5, .z = 4.22};
    ck_assert(CheckPointCircleCollision(&a, &c) == true);
    ck_assert(CheckPointCircleCollision(&a, &c2) != true);
}
END_TEST

START_TEST(t_point_triangle_collision) {
    Point2D a = {5, 3};
    Triangle t = {.x1 = 1, .y1 = 2, .x2 = 6, .y2 = 2, .x3 = 5, .y3 = 5};
    ck_assert(CheckPointTriangleCollision(&a, &t) == true);
}
END_TEST

START_TEST(t_circle_circle_collision) {
    Circle c = {.x = 0, .y = 5, .z = 4};
    Circle d = {.x = 10, .y = 5, .z = 6};
    Circle e = {.x = 10, .y = 5, .z = 5.999};
    ck_assert(CheckCircleCircleCollision(&c, &d) == true);
    ck_assert(CheckCircleCircleCollision(&c, &e) != true);
}
END_TEST

START_TEST(t_circle_line_collision) {
    Circle c = {.x = 0, .y = 0, .z = 5};
    Line2D l = {.x1 = 7.071059, .y1 = 0, .x2 = 0, .y2 = 7.071059};
    Line2D l2 = {.x1 = 7.1, .y1 = 0, .x2 = 0, .y2 = 7.1};

    ck_assert(CheckCircleLineCollision(&c, &l) == true);
    ck_assert(CheckCircleLineCollision(&c, &l2) != true);
}
END_TEST

START_TEST(t_circle_rect_collision) {
    Circle c = {.x = 0, .y = 0, .z = 5};
    Rect2D r = {.x1 = -2, .y1 = -6, .x2 = 2, .y2 = -10};
    Rect2D r2 = {.x1 = -6, .y1 = 4, .x2 = -4, .y2 = 2};
    Rect2D r3 = {-4, 2, 0, 0};
    Rect2D r4 = {-10, 10, 10, -10};
    ck_assert(CheckCircleRectCollision(&c, &r2) == true);
    ck_assert(CheckCircleRectCollision(&c, &r3) == true);
    ck_assert(CheckCircleRectCollision(&c, &r) != true);
    ck_assert(CheckCircleRectCollision(&c, &r4) == true);
}
END_TEST

START_TEST(t_line_line_collision) {
    Line2D a = {.x1 = 1, .y1 = 2, .x2 = 6, .y2 = 2};
    Line2D b = {.x1 = 3, .y1 = 5, .x2 = 2, .y2 = 5};
    ck_assert(CheckLineLineCollision(&a.a, &a.b, &b.a, &b.b) != true);
}
END_TEST

START_TEST(t_rect_line_collision) {
    Rect2D r = {.x1 = -1, .y1 = 1, .x2 = 1, .y2 = -1};
    Line2D l = {.x1 = -1.25, .y1 = -1.25, .x2 = -1.02, .y2 = 1.02};
    Vector2 rp2 = {r.x2, r.y1};
    Vector2 rp4 = {r.x1, r.y2};
    ck_assert(CheckRectLineCollision(&r.a, &rp2, &r.b, &rp4, &l.a, &l.b) !=
              true);
}
END_TEST

Suite* CollisionSuite() {
    Suite* s = suite_create("Collision");
    TCase* tc_core = tcase_create("TCore");

    tcase_add_test(tc_core, t_point_point_collision);
    tcase_add_test(tc_core, t_point_circle_collision);
    tcase_add_test(tc_core, t_point_triangle_collision);
    tcase_add_test(tc_core, t_circle_circle_collision);
    tcase_add_test(tc_core, t_circle_line_collision);
    tcase_add_test(tc_core, t_circle_rect_collision);
    tcase_add_test(tc_core, t_line_line_collision);
    tcase_add_test(tc_core, t_rect_line_collision);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int number_failed;
    Suite* s = CollisionSuite();
    SRunner* r = srunner_create(s);

    srunner_run_all(r, CK_NORMAL);
    number_failed = srunner_ntests_failed(r);
    srunner_free(r);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
    /* int a = 50; */
    /* double value = *(double*)&a; */

    /* printf("%d , %lf", a, value); */

    /* int y = 10; */
    /* int* z = &y; */
    /* printf("%p", (void*)z); */

    /* Point2D e = (Point2D){5, 8}; */
    /* uint* x = (unsigned int*)&e; */

    /* printf("%p\n", (void*)x); */
    /* printf("Sizeof struct Entity: %ld\n", sizeof(e)); */
    /* printf("%p\n", (void*)(&e)); */

    /* Vector2 e1 = {10, 20}; */
    /* printf("%f, %f\n", e1.x, e1.y); */

    /* Point2D e2 = {11, 22}; */
    /* printf("%f, %f\n", e2.x, e2.y); */

    /* Rect2D r1 = {.x1 = 10, .y1 = 20, .x2 = 40, .y2 = 40}; */
    /* printf("(%f, %f) (%f, %f)\n", r1.x1, r1.y1, r1.x2, r1.y2); */
    /* printf("(%f, %f) (%f, %f)\n", r1.a.x, r1.a.y, r1.b.x, r1.b.y); */

    /* Circle cir = {.x = 0, .y = 0, .z = 5}; */
    /* Vector2 temp = cir.center; */

    /* printf("(%f, %f) - %f\n", temp.x, temp.y, cir.radius); */

    /* distance(e2); */
}
