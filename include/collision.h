#ifndef COLLISION_HEADER
#define COLLISION_HEADER

#include <stdbool.h>

#include "types.h"

bool CheckPointPointCollision( const Vector2* , const Vector2* );
bool CheckPointCircleCollision( const Vector2*, const Vector3* );
bool CheckPointRectCollision( const Vector2*, const Vector4* );
bool CheckPointLineCollision( const Vector2*, const Vector4* );
bool CheckPointTriangleCollision( const Vector2*, const Triangle*);

bool CheckCircleCircleCollision( const Vector3*, const Vector3* );
bool CheckCircleRectCollision( const Vector3*, const Vector4* );
bool CheckCircleLineCollision( const Vector3*, const Vector4* );

bool CheckRectRectCollision( const Vector4*, const Vector4* );
bool CheckRectLineCollision( const Vector4*, const Vector4* );

bool CheckLineLineCollision( const Vector4*, const Vector4* );

#endif