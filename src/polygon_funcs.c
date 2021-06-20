#include "polygon_funcs.h"


#include <stdlib.h>
#include <stdio.h>
#include "types.h"


// Polygon2D CreatePolygon(const unsigned int count) {
// 	Polygon2D p;
// 	p.count = count;
// 	p.points = malloc(sizeof(Point2D) * count);
// 	return p;
// }

// Rect2D GetBoundingBox(const Polygon2D* p) {
// 	if(p->count == 0 || p->points == NULL)
// 		return (Rect2D){0,0,0,0};

// 	real_t minx, miny, maxx, maxy;
// 	minx = maxx = p->points[0].x;
// 	miny = maxy = p->points[0].y;

// 	Vector2 temp;
	
// 	for(size_t i = 1; i < p->count; i++) {
// 		temp = p->points[i];
// 		if( temp.x < minx)
// 			minx = temp.x;
// 		else if(temp.x > maxx)
// 			maxx = temp.x;
// 		if(temp.y < miny)
// 			miny = temp.y;
// 		else if(temp.y > maxy)
// 			maxy = temp.y;
// 	}

// 	Rect2D r = {minx, miny, maxx, maxy};
// 	return r;
// }



// linked_list function
// Rect2D GetBoundingBox(const Polygon2D* p) {
// 	if(p->count == 0 || p->points->head == NULL)
// 		return (Rect2D){0,0,0,0};

// 	real_t minx, miny, maxx, maxy;

// 	// first node
// 	minx = maxx = (p->points)->head->data.x;
// 	miny = maxy = (p->points)->head->data.y;

// 	Vec2_LL_node* trav = (p->points)->head->next; // traversal node
// 	while(trav!=NULL) {
// 		if( trav->data.x < minx)
// 			minx = trav->data.x;
// 		else if(trav->data.x > maxx)
// 			maxx = trav->data.x;
// 		if(trav->data.y < miny)
// 			miny = trav->data.y;
// 		else if(trav->data.y > maxy)
// 			maxy = trav->data.y;
// 		trav = trav->right; // next node
// 	}

// 	Rect2D r = {minx, miny, maxx, maxy};
// 	return r;
// }

// void PrintPolygon(const Polygon2D* p) {
// 	LL_PrintForward(p->points);
// }


// void AddVertex(Polygon2D * p, const Point2D* cord, const unsigned int position) {
// 	LL_InsertAtHead(p->points, *cord);
// }

// void RemovePolygon(Polygon2D* p) {
// 	LL_DeleteList(p->points);
// }