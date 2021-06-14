#ifndef DYNAMICS_HEADER
#define DYNAMICS_HEADER

#include "types.h"

#include <stdint.h>

#define MAX_FORCES 100
#define MAX_IMPLUSES 100

typedef struct {
	real_t mass;
	Vector2 pos;
	Vector2 vel;
	Vector2* force_list;
	uint8_t cforce;
	Vector2* impluse_list;
	uint8_t cimpulse;
} Object2D;


void AddForce(Object2D* object, const Vector2 force);
void RemoveForce(Object2D* object, const Vector2 force);
Vector2 TotalForce(const Object2D* object);

#endif // DYNAMICS_HEADER