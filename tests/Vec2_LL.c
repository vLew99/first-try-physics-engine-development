#include <stdio.h>

#include "types.h"
#include "data_structures/linked_list.h"

int main(int argc, char const *argv[])
{
	Vec2_LL_node* head = NULL;
	LL_TraverseForw(head);

	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));


	LL_Insert(&head, (Vector2){1, 2});
	LL_TraverseForw(head);



	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));


	LL_Insert(&head, (Vector2){2, 3});
	LL_TraverseForw(head);
	
	
	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));


	LL_Insert(&head, (Vector2){3, 4});
	LL_TraverseForw(head);
	

	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));
	

	LL_Insert(&head, (Vector2){4, 5});
	LL_TraverseForw(head);

	
	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));
	

	LL_Delete(&head, (Vector2){3, 4});
	LL_TraverseForw(head);


	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));


	LL_Delete(&head, (Vector2){1, 2});
	LL_Delete(&head, (Vector2){4, 5});
	LL_Delete(&head, (Vector2){2, 3});

	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));


	LL_Delete(&head, (Vector2){2, 3});


	printf("Is empty: %d\n", LL_IsEmpty(head));
	printf("List Count: %d\n", LL_GetCount(head));
	
	
	LL_TraverseForw(head);

	return 0;
}