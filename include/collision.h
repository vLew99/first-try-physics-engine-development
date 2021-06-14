#ifndef COLLISION_HEADER
#define COLLISION_HEADER

#include <stdbool.h>

#include "types.h"
#include "polygon_funcs.h"

bool CheckPointPointCollision( const Vector2* , const Vector2* );
bool CheckPointCircleCollision( const Vector2*, const Vector3* );
bool CheckPointRectCollision( const Vector2*, const Vector2* , const Vector2*);
bool CheckPointLineCollision( const Vector2*, const Vector4* );
bool CheckPointTriangleCollision( const Vector2*, const Triangle*);

bool CheckCircleCircleCollision( const Vector3*, const Vector3* );
bool CheckCircleRectCollision( const Vector3*, const Vector4* );
bool CheckCircleLineCollision( const Vector3*, const Vector4* );

bool CheckRectRectCollision( 
	const Vector4* rectangle_1,
	const Vector4* rectangle_2);

bool CheckRectLineCollision(
	const Vector2* rectangle_point_1,
	const Vector2* rectangle_point_2,
	const Vector2* rectangle_point_3,
	const Vector2* rectangle_point_4,
	const Vector2* line_point_1,
	const Vector2* line_point_2);

bool CheckLineLineCollision(
	const Vector2* line_1_point_1,
	const Vector2* line_1_point_2,
	const Vector2* line_2_point_1,
	const Vector2* line_2_point_2);

bool CheckPolyPointCollision(
	const Polygon2D* polygon,
	const Vector2* point);

#endif