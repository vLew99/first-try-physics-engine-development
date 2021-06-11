#include "vector_funcs.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Vector2* Add1(const Vector2* a, const Vector2* b) { // dynamically allocated on the heap
	Vector2* s = (Vector2*) malloc(sizeof(Vector2));
	s->x = a->x + b->x;
	s->y = a->y + b->y;
	return s;
}

Vector2 Add2(const Vector2* a, const Vector2* b) {
	return (Vector2){a->x + b->x, a->y + b->y};
}

Vector2 Subtract(const Vector2* a, const Vector2* b) {
	return (Vector2) {a->x - b->x, a->y - b->y};
}

real_t Norm(const Vector2 * a) {
#if USE_DOUBLE
	return sqrt(a->x*a->x + a->y*a->y);
#else
	return sqrtf(a->x*a->x + a->y*a->y);
#endif
}

real_t Dot(const Vector2* a, const Vector2* b) {
	return a->x*b->x + a->y*b->y;
}

Vector2 Normalize(const Vector2* a) {
	real_t n = Norm(a);
	return (Vector2){a->x/n, a->y/n};
}