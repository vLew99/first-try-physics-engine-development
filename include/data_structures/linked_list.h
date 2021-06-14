#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <stdint.h>
#include <stdbool.h>
#include "types.h"

typedef struct Vec2_LL_node {
	Vector2 data;
	struct Vec2_LL_node* left;
	struct Vec2_LL_node* right;
} Vec2_LL_node;



void LL_TraverseForw(Vec2_LL_node** list);
void LL_TraverseBack(Vec2_LL_node** list); // why can't i pass this as a const
void LL_Insert(Vec2_LL_node** list, const Vector2 item);
void LL_Delete(Vec2_LL_node** list, const Vector2 item);
unsigned int LL_GetCount(const Vec2_LL_node* list);
bool LL_IsEmpty(const Vec2_LL_node* list);




#endif // LINKED_LIST_HEADER