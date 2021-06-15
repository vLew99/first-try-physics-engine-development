#ifndef POLYGON_FUNCS_HEADER
#define POLYGON_FUNCS_HEADER

#include "data_structures/linked_list.h"
#include "types.h"


typedef struct {
	unsigned int count;
	Vec2_LL_node* points;
} Polygon2D;


void PrintPolygon(const Polygon2D* polygon);

Polygon2D CreatePolygon(const unsigned int num_of_points);

Rect2D GetBoundingBox(const Polygon2D* polygon);

void AddVertex(
	Polygon2D* polygon,
	const Point2D* point,
	const unsigned int position);

void RemovePolygon(Polygon2D* polygon);

#endif // POLYGON_HEADER