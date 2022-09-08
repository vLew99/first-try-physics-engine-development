#include "polygon_funcs.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

Rect2D GetBoundingBox(const Polygon2D* p) {
    if (p->count == 0 || p->head == NULL) return (Rect2D){0, 0, 0, 0};

    real_t minx, miny, maxx, maxy;

    minx = maxx = p->head->data.x;
    miny = maxy = p->head->data.x;

    LLN_Vector2* trav = p->head->next;
    Vector2* temp;

    while (trav != NULL) {
        temp = &trav->data;
        if (temp->x < minx)
            minx = temp->x;
        else if (temp->x > maxx)
            maxx = temp->x;
        if (temp->y < miny)
            miny = temp->y;
        else if (temp->y > maxy)
            maxy = temp->y;

        trav = trav->next;
    }

    Rect2D r = {minx, miny, maxx, maxy};
    return r;
}
