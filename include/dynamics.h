#ifndef DYNAMICS_HEADER
#define DYNAMICS_HEADER

#include <stdint.h>

#include "data_structures/linked_list.h"
#include "types.h"

typedef struct {
    real_t mass;
    Vector2 pos;
    Vector2 vel;
    LL_Vector2 force_list;
    LL_Vector2 impulse_list;
} Object2D;

Object2D* CreateObject2D(const real_t mass, const Vector2 pos,
                         const Vector2 vel);
void DeleteObject2D(Object2D* obj);

void AddForce(Object2D* object, const Vector2 force);
void RemoveForce(Object2D* object, const Vector2 force);
Vector2 TotalForce(const Object2D* object);

#endif  // DYNAMICS_HEADER
