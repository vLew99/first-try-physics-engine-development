#include "data_structures/linked_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

// Create a new node
// sets value , prev , next
LLN_Vector2* LL_CreateNode(const Vector2 item, LLN_Vector2* prev,
                           LLN_Vector2* next) {
    LLN_Vector2* newnode = malloc(sizeof(*newnode));
    newnode->data = item;
    newnode->next = next;
    newnode->prev = prev;
    return newnode;
}

/////////////////////
// QUERY FUNCTIONS //
/////////////////////

/*
                Print Linked List from front to back
 */
void LL_PrintForward(const LL_Vector2* list) {
    LLN_Vector2* trav = list->head;
    while (trav != NULL) {
        printf("(%p,(%f, %f),%p)->\n", (void*)trav->prev, trav->data.x,
               trav->data.y, (void*)trav->next);
        trav = trav->next;
    }
    printf("\n");
}

/*
                Print Linked List from back to front
 */
void LL_PrintBackward(const LL_Vector2* list) {
    LLN_Vector2* trav = list->tail;
    while (trav != NULL) {
        printf("(%p,(%f, %f),%p)->\n", (void*)trav->next, trav->data.x,
               trav->data.y, (void*)trav->prev);
        trav = trav->prev;
    }
    printf("\n");
}

////////////////////////////
// INSERT / ADD FUNCTIONS //
////////////////////////////

/*
                Insert new node at head of Linked List
 */
void LL_InsertAtHead(LL_Vector2* list, const Vector2 item) {
    LLN_Vector2* newnode = LL_CreateNode(item, NULL, list->head);

    if (list->head != NULL) {
        (list->head)->prev = newnode;
    } else {
        list->tail = newnode;
    }

    list->head = newnode;
    list->count++;
}

/*
                Insert new node at tail of Linked List
*/
void LL_InsertAtTail(LL_Vector2* list, const Vector2 item) {
    LLN_Vector2* newnode = LL_CreateNode(item, list->tail, NULL);

    if (list->tail == NULL) {
        list->head = newnode;
    } else {
        list->tail->next = newnode;
    }

    list->tail = newnode;
    list->count++;
}

void LL_InsertAtIndex(LL_Vector2* list, const int pos) {}

//////////////////////
// DELETE FUNCTIONS //
//////////////////////

/*
                Delete the entire Linked List
 */
void LL_DeleteList(LL_Vector2* list) {
    LLN_Vector2* trav = list->head;
    LLN_Vector2* next;
    while (trav != NULL) {
        next = trav->next;
        free(trav);
        trav = next;
    }
    list->count = 0;
}

/*
                Delete Head from Linked List.
 */
void LL_DeleteHead(LL_Vector2* list) {
    if (list->count == 0)  // no node
        return;
    else if (list->count == 1)  // a single node
    {
        free(list->head);
        list->tail = NULL;
    } else  // more than one node
    {
        LLN_Vector2* temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    list->count--;
}

/*
                Delete Tail from Linked List.
 */
void LL_DeleteTail(LL_Vector2* list) {
    if (list->count == 0)
        return;
    else if (list->count == 1) {
        free(list->tail);
        list->head = NULL;
    } else {
        LLN_Vector2* temp = list->tail->prev;
        temp->next = NULL;
        free(list->tail);
        list->tail = temp;
    }
    list->count--;
}

void LL_DeleteNode(LL_Vector2* list, const Vector2 item) {}

/////////////////////
// HELPER FUNCTION //
/////////////////////

/*
                Checks if the Linked List is empty or not.
 */
bool LL_IsEmpty(const LL_Vector2* list) { return list->count == 0; }

/*
                Returns  a pointer to an array containing all items in the
   Linked List.
 */
Vector2* LL_ToArray(const LL_Vector2* list) {
    // create dynamically allocated array
    Vector2* arr = malloc(sizeof(*arr) * (list->count));

    // traverse
    LLN_Vector2* trav = list->head;
    for (int i = 0; trav != NULL; i++) {
        arr[i] = trav->data;
        trav = trav->next;
    }

    return arr;
}

/*
                Returns the count of items in Linked List.
 */
int LL_GetCount(const LL_Vector2* list) { return list->count; }
