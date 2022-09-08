#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "polygon_funcs.h"


void Test1() {
	Polygon2D p = {0, NULL, NULL};
	LL_PrintForward(&p);
	Vector2 a = {1, 2};
	Vector2 b = (Vector2){1.5, 3};
	Vector2 c = (Vector2){2, 2};

	LL_InsertAtHead(&p, a);
	LL_InsertAtHead(&p, b);
	LL_InsertAtHead(&p, c);
	LL_PrintForward(&p);

	LL_DeleteHead(&p);
	LL_PrintForward(&p);
}



void Test2()
{

	Polygon2D p = {0, NULL, NULL};

	Vector2 a = {2, 4};
	Vector2 b = (Vector2){3, 1};
	Vector2 c = (Vector2){5, 4};
	Vector2 d = {4, 6};
	Vector2 e = {3, 7};

	LL_InsertAtHead(&p, a);
	LL_InsertAtHead(&p, b);
	LL_InsertAtHead(&p, c);
	LL_InsertAtTail(&p, d);
	LL_InsertAtTail(&p, e);


	LL_PrintForward(&p);
	

	// create bounding box
	Rect2D bb = GetBoundingBox(&p);


	assert(bb.x1 == 2.0f);
	assert(bb.y1 == 1.0f);
	assert(bb.x2 == 5.0f);
	assert(bb.y2 == 7.0f);
	
	printf("--%f--%f--%f--%f--\n\n", bb.x1, bb.y1, bb.x2, bb.y2);

	LL_PrintForward(&p);

}

int main(int argc, char const *argv[])
{
	Test2();
	return 0;
}
