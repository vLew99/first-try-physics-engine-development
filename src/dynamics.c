#include "dynamics.h"
#include "types.h"

void AddForce(Object2D* object, const Vector2 force) {
	if (force.x == 0.0f && force.y == 0.0f)
		return;

	if (object->cforce >= MAX_FORCES) {
		return;
	}

	object->force_list[object->cforce++] = force;
}
