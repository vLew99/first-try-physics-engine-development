#ifndef VECTOR_FUNCS
#define VECTOR_FUNCS

#include <stdbool.h>

#include "types.h"

#define EqualV2(a, b) (a.x == b.x && a.y == b.y)
#define EqualV3(a, b) (a.x == b.x && a.y == b.y && a.z == b.z)

#define AddV2(a, b) \
    (Vector2) { a.x + b.x, a.y + b.y }
#define SubV2(a, b) \
    (Vector2) { a.x - b.x, a.y - b.y }

#if USE_DOUBLE
#define LenV2(a) sqrt(a.x* a.x + a.y * a.y)
#else
#define LenV2(a) sqrtf(a.x* a.x + a.y * a.y)
#endif

#define NormV2(a) \
    (Vector2) { a.x / LenV2(a), a.y / LenV2(a) }

#define DotV2(a, b) a.x* b.x + a.y* b.y
#define SqrMagV2(a, b) DotV2(a, b)

#define CrossV2(a, b) (a.x * b.y - a.y * b.x)

#endif  // VECTOR_FUNCS
