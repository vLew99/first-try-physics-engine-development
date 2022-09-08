#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "types.h"

// linked list of type Vector2

typedef struct LLN_Vector2 {
    Vector2 data;
    struct LLN_Vector2* next;
    struct LLN_Vector2* prev;
} LLN_Vector2;

typedef struct {
    size_t count;
    LLN_Vector2* head;
    LLN_Vector2* tail;
} LL_Vector2;

// node create function
LLN_Vector2* LL_CreateNode(const Vector2 item, LLN_Vector2* prev,
                           LLN_Vector2* next);

// query functions
void LL_PrintForward(const LL_Vector2* list);
void LL_PrintBackward(const LL_Vector2* list);
Vector2* LL_Get(const LL_Vector2* list);

// inserting nodes
void LL_InsertAtHead(LL_Vector2* list, const Vector2 item);
void LL_InsertAtTail(LL_Vector2* list, const Vector2 item);
void LL_InsertAtIndex(LL_Vector2* list, const int pos);

// deleting nodes
void LL_DeleteHead(LL_Vector2* list);
void LL_DeleteTail(LL_Vector2* list);
void LL_DeleteNode(LL_Vector2* list, const Vector2 item);
void LL_DeleteList(LL_Vector2* list);

// helper functions
Vector2* LL_ToArray(const LL_Vector2* list);
int LL_GetCount(const LL_Vector2* list);
bool LL_IsEmpty(const LL_Vector2* list);

#endif  // LINKED_LIST_HEADER
