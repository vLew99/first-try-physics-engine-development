#include "collision.h"

#include <math.h>
#include "defs.h"
#include "utils.h"



// POINT COLLISIONS
bool CheckPointPointCollision(const Vector2* a,const Vector2* b) {
	return a->x == b->x && a->y == b->y;
}


bool CheckPointCircleCollision(const Vector2* a, const Vector3* b) {
	return GetSquaredSum(a, &b->center) <= b->radius * b->radius;
}


bool CheckPointRectCollision(const Vector2* a, const Vector4* b) {
	return a->x >= b->x1 && a->x <= b->x2 && a->y >= b->y1 && a->y <= b->y2; 
}


bool CheckPointLineCollision(const Vector2* a, const Vector4* b) {
	return GetEuclideanDistance(a, &b->a) + GetEuclideanDistance(a, &b->b) == GetEuclideanDistance(&b->a, &b->b);
}


bool CheckPointTriangleCollision(const Vector2* a, const Triangle* t) {
	real_t sum_of_areas = GetTriangleArea(a, &t->a, &t->b) + GetTriangleArea(a, &t->b, &t->c) + GetTriangleArea(a, &t->c, &t->a);
	real_t area_of_triangle = GetTriangleArea(&t->a, &t->b, &t->c);
	#ifdef DOUBLE
		return fabsf(sum_of_areas - area_of_triangle) <= ERROR;
	#else
		return fabs(sum_of_areas - area_of_triangle) <= ERROR;
	#endif
}



// CIRCLE COLLISIONS
bool CheckCircleCircleCollision(const Vector3* a, const Vector3* b) {
	real_t temp = a->radius + b->radius;
	return GetSquaredSum(&a->center, &b->center) <= temp*temp;
}


bool CheckCircleRectCollision(const Vector3* c, const Vector4* r) {
	Vector2 p = c->center;

	// these conditionals create the closest point to the circle on the rectangle
	if(c->x < r->x1 )
		p.x = r->x1;
	else if( c->x > r->x2 )
		p.x = r->x2;

	if(c->y > r->y1 ) // this assumes that the y axis is from bottom  to top  and not the other way around.
		p.y = r->y1;
	else if( c->y < r->y2 )
		p.y = r->y2;

	// don't use this - as we are only comparing values tha absolute value of distance doesn't matter
	// but sqrt takes a lot of resource and time to calculate
	// return GetEuclideanDistance(p, c.center) <= c.radius;
	
	return GetSquaredSum(&p, &c->center) <= (c->radius * c->radius);
}


bool CheckCircleLineCollision(const Vector3* c, const Vector4* l) {
	// if either end collides with the circle
	if( CheckPointCircleCollision(&l->a, c) || CheckPointCircleCollision(&l->b, c))
		return true;

	real_t x1, y1, x2, y2, cx, cy;
	
	x1 = l->x1;
	y1 = l->y1;
	x2 = l->x2;
	y2 = l->y2;
	cx = c->x;
	cy = c->y;

	real_t u = (x2 - x1) * (cx - x1) + (cy - y1) * (y2 - y1);
	u /= GetSquaredSum(&l->a, &l->b);

	Vector2 temp;
	temp.x = (x1 + u * (x2 - x1));
	temp.y = (y1 + u * (y2 - y1));

	if(CheckPointLineCollision(&temp, l) && CheckPointCircleCollision(&temp, c))
		return true;
	return false;
}


// RECT COLLISIONS

bool CheckRectRectCollision(const Vector4* a, const Vector4* b) {
	return !(a->x1 > b->x2 || a->x2 < b->x1 || a->y1 < b->y2 || a->y2 > b->y1);
}