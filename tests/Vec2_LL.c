#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "data_structures/linked_list.h"
#include "types.h"
#include "vector_funcs.h"

START_TEST(t_ll_initialize) {
    LL_Vector2 list = {0, NULL, NULL};
    ck_assert_ptr_null(list.head);
    ck_assert_ptr_null(list.tail);
    ck_assert(LL_IsEmpty(&list));
}
END_TEST

START_TEST(t_ll_InsertHead) {
    LL_Vector2 list = {0, NULL, NULL};
    ck_assert_int_eq(LL_GetCount(&list), 0);

    LL_InsertAtHead(&list, (Vector2){2, 3});

    Vector2 temp = (Vector2){2, 3};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp));
    ck_assert_int_eq(LL_GetCount(&list), 1);

    LL_InsertAtHead(&list, (Vector2){10, 16});
    Vector2 temp2 = (Vector2){10, 16};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp2));
    ck_assert(EqualV2(LL_Get(&list, 1)->data, temp));
    ck_assert_int_eq(LL_GetCount(&list), 2);

    LL_InsertAtHead(&list, (Vector2){14, 14});
    Vector2 temp3 = (Vector2){14, 14};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp3));
    ck_assert(EqualV2(LL_Get(&list, 1)->data, temp2));
    ck_assert(EqualV2(LL_Get(&list, 2)->data, temp));
    ck_assert_int_eq(LL_GetCount(&list), 3);
}
END_TEST

START_TEST(t_ll_InsertTail) {
    LL_Vector2 list = {0, NULL, NULL};
    ck_assert_int_eq(LL_GetCount(&list), 0);

    LL_InsertAtTail(&list, (Vector2){43, 13});
    Vector2 temp = (Vector2){43, 13};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp));
    ck_assert_int_eq(LL_GetCount(&list), 1);

    LL_InsertAtTail(&list, (Vector2){12, 12});
    Vector2 temp2 = (Vector2){12, 12};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp));
    ck_assert(EqualV2(LL_Get(&list, 1)->data, temp2));
    ck_assert_int_eq(LL_GetCount(&list), 2);

    LL_InsertAtTail(&list, (Vector2){14, 14});
    Vector2 temp3 = (Vector2){14, 14};
    ck_assert(EqualV2(LL_Get(&list, 0)->data, temp));
    ck_assert(EqualV2(LL_Get(&list, 1)->data, temp2));
    ck_assert(EqualV2(LL_Get(&list, 2)->data, temp3));
    ck_assert_int_eq(LL_GetCount(&list), 3);
}
END_TEST

/*
 * TODO: t_ll_InsertNode
 */

/*
 * START_TEST(t_ll_InsertNode) {
 *     LL_Vector2 list = {0, NULL, NULL};
 *     LL_InsertAtIndex(&list, (Vector2){1, 1}, 0);
 * }
 * END_TEST
 */

/* START_TEST(t_ll_InsertHead1) { */
    /* LL_Vector2 list = {0, NULL, NULL}; */
    /* LL_InsertAtHead(&list, (Vector2){2, 3}); */

    /* ck_assert_ptr_nonnull(list.head); */
    /* ck_assert_ptr_eq(list.head, list.tail); */
    /* ck_assert_ptr_null(list.head->next); */
    /* ck_assert_ptr_null(list.head->prev); */
    /* ck_assert_int_eq(list.count, 1); */

    /* // value compare */
    /* ck_assert_int_eq(list.head->data.x, 2); */
    /* ck_assert_int_eq(list.head->data.y, 3); */

    /* LL_InsertAtHead(&list, (Vector2){10, 16}); */

    /* ck_assert_ptr_nonnull(list.head); */
    /* ck_assert_ptr_nonnull(list.tail); */
    /* ck_assert(list.head != list.tail); */

    /* ck_assert_ptr_null(list.head->prev); */
    /* ck_assert_ptr_null(list.tail->next); */
    /* ck_assert_ptr_eq(list.head->next, list.tail); */
    /* ck_assert_ptr_eq(list.tail->prev, list.head); */

    /* ck_assert_int_eq(list.count, 2); */

    /* ck_assert_int_eq(list.head->data.x, 10); */
    /* ck_assert_int_eq(list.head->data.y, 16); */
    /* ck_assert_int_eq(list.tail->data.x, 2); */
    /* ck_assert_int_eq(list.tail->data.y, 3); */
/* } */
/* END_TEST */

/* START_TEST(t_ll_InsertTail1) { */
    /* LL_Vector2 list = {0, NULL, NULL}; */
    /* LL_InsertAtTail(&list, (Vector2){43, 13}); */

    /* ck_assert_ptr_nonnull(list.head); */
    /* ck_assert_ptr_eq(list.head, list.tail); */
    /* ck_assert_ptr_null(list.head->next); */
    /* ck_assert_ptr_null(list.head->prev); */
    /* ck_assert_int_eq(list.count, 1); */

    /* ck_assert_int_eq(list.head->data.x, 43); */
    /* ck_assert_int_eq(list.head->data.y, 13); */

    /* LL_InsertAtTail(&list, (Vector2){12, 12}); */

    /* ck_assert_ptr_nonnull(list.head); */
    /* ck_assert_ptr_nonnull(list.tail); */
    /* ck_assert(list.head != list.tail); */

    /* ck_assert_ptr_null(list.head->prev); */
    /* ck_assert_ptr_null(list.tail->next); */
    /* ck_assert_ptr_eq(list.head->next, list.tail); */
    /* ck_assert_ptr_eq(list.tail->prev, list.head); */

    /* ck_assert_int_eq(list.count, 2); */

    /* ck_assert_int_eq(list.head->data.x, 43); */
    /* ck_assert_int_eq(list.head->data.y, 13); */
    /* ck_assert_int_eq(list.tail->data.x, 12); */
    /* ck_assert_int_eq(list.tail->data.y, 12); */
/* } */
/* END_TEST */

Suite* linkedListSuite(void) {
    Suite* s = suite_create("linkedlist");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, t_ll_initialize);
    tcase_add_test(tc_core, t_ll_InsertHead);
    tcase_add_test(tc_core, t_ll_InsertTail);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(int argc, char const* argv[]) {
    int number_failed;
    Suite* s = linkedListSuite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    /* srunner_run(sr, "linkedlist", "Mine", CK_NORMAL); */

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
