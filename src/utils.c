#include "utils.h"

#include <math.h>

#include "types.h"


inline real_t GetSquaredSum(const Vector2* a, const Vector2* b) {
	real_t temp1 = a->x - b->x;
	real_t temp2 = a->y - b->y;
	return temp1*temp1 + temp2*temp2;
}


real_t GetEuclideanDistance(const Vector2* a, const Vector2* b) {
#ifdef USE_DOUBLE
	return sqrt(GetSquaredSum(a, b));
#else
	return sqrtf(GetSquaredSum(a, b));
#endif
}


real_t GetTriangleArea(const Vector2* x, const Vector2* y, const Vector2* z) {
	real_t a = GetEuclideanDistance(x, y);
	real_t b = GetEuclideanDistance(y, z);
	real_t c = GetEuclideanDistance(z, x);
	// printf()
	real_t s = (a + b + c)/2;
	real_t area;
#ifdef USE_DOUBLE
	area = sqrt(s*(s-a)*(s-b)*(s-c));
#else
	area = sqrtf(s*(s-a)*(s-b)*(s-c));
#endif
	return area;
}
