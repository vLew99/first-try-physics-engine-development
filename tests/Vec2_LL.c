#include <stdio.h>

#include "data_structures/linked_list.h"
#include "types.h"

int main(int argc, char const* argv[]) {
    LL_Vector2 list = {0, NULL, NULL};
    LL_PrintForward(&list);

    printf("Is empty: %d\n", LL_IsEmpty(&list));
    printf("List Count: %ld\n", list.count);

    LL_InsertAtHead(&list, (Vector2){1, 2});
    LL_PrintForward(&list);

    printf("Is empty: %d\n", LL_IsEmpty(&list));
    printf("List Count: %ld\n", list.count);

    LL_InsertAtHead(&list, (Vector2){2, 3});
    LL_PrintForward(&list);

    printf("Is empty: %d\n", LL_IsEmpty(&list));
    printf("List Count: %ld\n", list.count);

    LL_InsertAtTail(&list, (Vector2){3, 4});
    LL_PrintForward(&list);

    printf("Is empty: %d\n", LL_IsEmpty(&list));
    printf("List Count: %ld\n", list.count);

    LL_InsertAtTail(&list, (Vector2){4, 5});
    LL_PrintForward(&list);

    printf("Is empty: %d\n", LL_IsEmpty(&list));
    printf("List Count: %ld\n", list.count);

    Vector2* arr = LL_ToArray(&list);
    int count = LL_GetCount(&list);
    for (int i = 0; i < count; i++) {
        printf("(%f, %f)-> ", arr[i].x, arr[i].y);
    }
    printf("\n");

    LL_PrintBackward(&list);

    return 0;
}
