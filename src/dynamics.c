#include "dynamics.h"

#include <stdio.h>
#include <stdlib.h>

#include "data_structures/linked_list.h"
#include "types.h"

Object2D* CreateObject2D(const real_t mass, const Vector2 pos,
                         const Vector2 vel) {
    Object2D* obj = malloc(sizeof(*obj));
    obj->mass = mass;
    obj->pos = pos;
    obj->vel = vel;
    obj->force_list = (LL_Vector2){
        0,
        NULL,
        NULL,
    };
    obj->impulse_list = (LL_Vector2){
        0,
        NULL,
        NULL,
    };
    return obj;
}

void DeleteObject2D(Object2D* obj) {
    LL_DeleteList(&obj->force_list);
    LL_DeleteList(&obj->impulse_list);
    free(obj);
}

void AddForce(Object2D* object, const Vector2 force) {
    if (force.x == 0.0f && force.y == 0.0f) return;
    LL_InsertAtTail(&object->force_list, force);
}

void RemoveForce(Object2D* object, const Vector2 force) {
    if (force.x == 0.0f && force.y == 0.0f) return;
    LL_DeleteNode(&object->force_list, force);
}

void AddImpulse(Object2D* object, const Vector2 impulse) {
    if (impulse.x == 0.0f && impulse.y == 0.0f) return;
    LL_InsertAtTail(&object->impulse_list, impulse);
}

void RemoveImpulses(Object2D* object) { LL_DeleteList(&object->impulse_list); }

Vector2 TotalImpulse(const Object2D* object) {
    Vector2 sum = {0, 0};
    LLN_Vector2* trav = (object->impulse_list).head;
    while (trav != NULL) {
        sum.x += trav->data.x;
        sum.y += trav->data.y;
        trav = trav->next;
    }
    return sum;
}

Vector2 TotalForce(const Object2D* object) {
    Vector2 sum = {0, 0};
    LLN_Vector2* trav = (object->force_list).head;
    while (trav != NULL) {
        sum.x += trav->data.x;
        sum.y += trav->data.y;
        trav = trav->next;
    }

    return sum;
}

void ApplyForces(Object2D* object) {
    const Vector2 total_force = TotalForce(object);
    object->vel.x += total_force.x;
    object->vel.y += total_force.y;
}

void ApplyImpulses(Object2D* object) {
    const Vector2 total_impulse = TotalImpulse(object);
    object->vel.x += total_impulse.x;
    object->vel.y += total_impulse.y;
    RemoveImpulses(object);
}
