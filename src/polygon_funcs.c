#include "polygon_funcs.h"


#include <stdlib.h>
#include <stdio.h>
#include "types.h"



Polygon2D CreatePolygon(const unsigned int count) {
	Polygon2D p;
	p.count = count;
	p.points = malloc(sizeof(Point2D) * count);
	return p;
}

Rect2D GetBoundingBox(const Polygon2D* p) {
	if(p->count == 0 || p->points == NULL)
		return (Rect2D){0,0,0,0};

	real_t minx, miny, maxx, maxy;
	minx = maxx = p->points[0].x;
	miny = maxy = p->points[0].y;

	Vector2 temp;
	
	for(size_t i = 1; i < p->count; i++) {
		temp = p->points[i];
		if( temp.x < minx)
			minx = temp.x;
		else if(temp.x > maxx)
			maxx = temp.x;
		if(temp.y < miny)
			miny = temp.y;
		else if(temp.y > maxy)
			maxy = temp.y;
	}

	Rect2D r = {minx, miny, maxx, maxy};
	return r;

}

void PrintPolygon(const Polygon2D* p) {
	for(size_t i = 0; i< p->count; i++) {
		printf("(%f, %f)\n", p->points[i].x, p->points[i].y);
	}
}


void AddVertex(Polygon2D * p, const Point2D* cord, const unsigned int position) {
	if(position >= 0 && position < p->count) {
		p->points[position] = *cord;
	}
}

void RemovePolygon(Polygon2D* p) {
	free(p->points);
}