#include "data_structures/linked_list.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "types.h"



void LL_PrintForward(const Vec2_LL_node* trav) {
	while(trav != NULL) {
		printf("(%p,(%f, %f),%p)->\n", trav->left, trav->data.x, trav->data.y, trav->right);
		trav = trav->right;
	}
	printf("\n");
}

void LL_PrintBackward(const Vec2_LL_node* trav) {
	while(trav != NULL) {
		printf("(%p,(%f, %f),%p)->\n", trav->left, trav->data.x, trav->data.y, trav->right);
		trav = trav->left;
	}
	printf("\n");
}



void LL_Insert(Vec2_LL_node** list, const Vector2 item) {
	
	// create new node
	Vec2_LL_node* new = (Vec2_LL_node*) malloc(sizeof(*new));
	
	new->data = item;
	new->right = NULL;
	
	// traverser
	Vec2_LL_node* temp = *list;
	
	if(temp == NULL) {

		// put data in new
		new->left = NULL;

		// change first node to new
		*list = new;

		return;
	}
	else {

		while(temp->right !=NULL) {
			temp = temp->right;
		}

		temp->right = new;
		new->left = temp;
	
	}
}



void LL_Delete(Vec2_LL_node** list, const Vector2 item) {
	Vec2_LL_node* temp = *list;
	while(temp!=NULL)
	{
		if(temp->data.x == item.x && temp->data.y == item.y)
		{

			if(temp->left==NULL)
				*list = temp->right;
			else
				(temp->left)->right = temp->right;


			if(temp->right != NULL)
				(temp->right)->left = temp->left;

			free(temp);
			break;

		}
		temp = temp->right;
	}
}


void LL_DeleteLL(Vec2_LL_node* list) {
	Vec2_LL_node* trav = list; // traversal node
	while(trav!= NULL) {
		trav = list->right;
		free(list);
		list = trav;
	}
}




unsigned int LL_GetCount(const Vec2_LL_node* list) {
	unsigned int count = 0;
	while(list!=NULL) {
		list = list->right;
		count++;
	}
	return count;
}

bool LL_IsEmpty(const Vec2_LL_node* list) {
	return list==NULL;
}
