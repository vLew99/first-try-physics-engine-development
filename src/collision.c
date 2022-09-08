#include "collision.h"

#include <math.h>
#include <stdio.h>

#include "defs.h"
#include "utils.h"

// POINT COLLISIONS
bool CheckPointPointCollision(const Vector2* a, const Vector2* b) {
    return a->x == b->x && a->y == b->y;
}

bool CheckPointCircleCollision(const Vector2* a, const Vector3* b) {
    return GetSquaredSum(a, &b->center) <= b->radius * b->radius;
}

bool CheckPointRectCollision(const Vector2* a, const Vector2* rp1,
                             const Vector2* rp3) {
    return a->x >= rp1->x && a->x <= rp3->x && a->y <= rp1->y && a->y >= rp3->y;
}

bool CheckPointLineCollision(const Vector2* a, const Vector4* b) {
    return GetEuclideanDistance(a, &b->a) + GetEuclideanDistance(a, &b->b) ==
           GetEuclideanDistance(&b->a, &b->b);
}

bool CheckPointTriangleCollision(const Vector2* a, const Triangle* t) {
    real_t sum_of_areas = GetTriangleArea(a, &t->a, &t->b) +
                          GetTriangleArea(a, &t->b, &t->c) +
                          GetTriangleArea(a, &t->c, &t->a);
    real_t area_of_triangle = GetTriangleArea(&t->a, &t->b, &t->c);
#ifdef DOUBLE
    return fabsf(sum_of_areas - area_of_triangle) <= ERROR;
#else
    return fabs(sum_of_areas - area_of_triangle) <= ERROR;
#endif
}

// CIRCLE COLLISIONS
bool CheckCircleCircleCollision(const Vector3* a, const Vector3* b) {
    real_t temp = a->radius + b->radius;
    return GetSquaredSum(&a->center, &b->center) <= temp * temp;
}

bool CheckCircleRectCollision(const Vector3* c, const Vector4* r) {
    Vector2 p = c->center;

    // these conditionals create the closest point to the circle on the
    // rectangle
    if (c->x < r->x1)
        p.x = r->x1;
    else if (c->x > r->x2)
        p.x = r->x2;

    if (c->y > r->y1)  // this assumes that the y axis is from bottom  to top
                       // and not the other way around.
        p.y = r->y1;
    else if (c->y < r->y2)
        p.y = r->y2;

    // don't use this - as we are only comparing values tha absolute value of
    // distance doesn't matter but sqrt takes a lot of resource and time to
    // calculate return GetEuclideanDistance(p, c.center) <= c.radius;

    return GetSquaredSum(&p, &c->center) <= (c->radius * c->radius);
}

bool CheckCircleLineCollision(const Vector3* c, const Vector4* l) {
    // if either end collides with the circle
    if (CheckPointCircleCollision(&l->a, c) ||
        CheckPointCircleCollision(&l->b, c))
        return true;

    real_t x1, y1, x2, y2, cx, cy;

    x1 = l->x1;
    y1 = l->y1;
    x2 = l->x2;
    y2 = l->y2;
    cx = c->x;
    cy = c->y;

    real_t u = (x2 - x1) * (cx - x1) + (cy - y1) * (y2 - y1);
    u /= GetSquaredSum(&l->a, &l->b);

    Vector2 temp;
    temp.x = (x1 + u * (x2 - x1));
    temp.y = (y1 + u * (y2 - y1));

    if (CheckPointLineCollision(&temp, l) &&
        CheckPointCircleCollision(&temp, c))
        return true;
    return false;
}

// RECT COLLISIONS

bool CheckRectRectCollision(const Vector4* a, const Vector4* b) {
    return !(a->x1 > b->x2 || a->x2 < b->x1 || a->y1 < b->y2 || a->y2 > b->y1);
}

bool CheckRectLineCollision(const Vector2* rp1, const Vector2* rp2,
                            const Vector2* rp3, const Vector2* rp4,
                            const Vector2* lp1, const Vector2* lp2) {
    if (CheckPointRectCollision(lp1, rp1, rp3) ||
        CheckPointRectCollision(lp2, rp1, rp3))
        return true;

    bool left, right, top, bottom;
    top = CheckLineLineCollision(rp1, rp2, lp1, lp2);
    right = CheckLineLineCollision(rp2, rp3, lp1, lp2);
    bottom = CheckLineLineCollision(rp3, rp4, lp1, lp2);
    left = CheckLineLineCollision(rp4, rp1, lp1, lp2);

    if (top || right || bottom || left) return true;

    return false;
}

// LINE COLLISIONS
bool CheckLineLineCollision(const Vector2* p1, const Vector2* p2,
                            const Vector2* p3, const Vector2* p4) {
    real_t x1 = p1->x;
    real_t y1 = p1->y;
    real_t x2 = p2->x;
    real_t y2 = p2->y;

    real_t x3 = p3->x;
    real_t y3 = p3->y;
    real_t x4 = p4->x;
    real_t y4 = p4->y;

    real_t d = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
    if (d == 0) return false;

    real_t u1 = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / d;
    real_t u2 = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / d;

    if (0 <= u1 && u1 <= 1 && 0 <= u2 && u2 <= 1) return true;
    return false;
}

// POLYGON COLLISIONS
bool CheckPolyPointCollision(const Polygon2D* p, const Vector2* a) {
    return true;  // to be written
}
