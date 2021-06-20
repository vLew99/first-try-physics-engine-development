#ifndef POLYGON_FUNCS_HEADER
#define POLYGON_FUNCS_HEADER

#include "data_structures/linked_list.h"
#include "types.h"


typedef LL_Vector2 Polygon2D;


Rect2D GetBoundingBox(const Polygon2D* polygon);

#endif // POLYGON_HEADER