#ifndef VECTOR_FUNCS
#define VECTOR_FUNCS

#include "types.h"


Vector2* Add1(const Vector2*, const Vector2*);
Vector2 Add2(const Vector2*, const Vector2*);
Vector2 Subtract(const Vector2*, const Vector2*);
real_t Norm(const Vector2*);
real_t Dot(const Vector2*, const Vector2*);
real_t Cross(const Vector2*, const Vector2*); // need to look at this
Vector2 Normalize(const Vector2*);

#endif // VECTOR_FUNCS