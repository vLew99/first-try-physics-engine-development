#ifndef COLLISION_HEADER
#define COLLISION_HEADER

#include <stdbool.h>

#include "types.h"

bool CheckPointPointCollision( const Vector2* , const Vector2* );
bool CheckPointCircleCollision( const Vector2*, const Vector3* );
bool CheckPointRectCollision( const Vector2*, const Vector2* , const Vector2*);
bool CheckPointLineCollision( const Vector2*, const Vector4* );
bool CheckPointTriangleCollision( const Vector2*, const Triangle*);

bool CheckCircleCircleCollision( const Vector3*, const Vector3* );
bool CheckCircleRectCollision( const Vector3*, const Vector4* );
bool CheckCircleLineCollision( const Vector3*, const Vector4* );

bool CheckRectRectCollision( const Vector4*, const Vector4* );
bool CheckRectLineCollision(const Vector2* rp1, const Vector2* rp2, const Vector2* rp3, const Vector2* rp4, const Vector2* lp1, const Vector2* lp2);

bool CheckLineLineCollision( const Vector2* , const Vector2* , const Vector2* ,const Vector2*);

#endif