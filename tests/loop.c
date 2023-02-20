#include <stdio.h>
#include <stdlib.h>

#include "dynamics.h"
#include "types.h"

void Draw(const Vector2 pos) {
    for (int i = 0; i < pos.y; i++) printf("\n");
    for (int i = 0; i < pos.x; i++) printf(" ");
    printf("#");
    for (int i = 0; i < 41 - pos.y; i++) printf("\n");
}

void update(Object2D* player) {
    player->pos.x += player->vel.x;
    player->pos.y += player->vel.y;

    if (player->pos.y >= 41 || player->pos.y < 0) {
        player->vel.y *= -1;
    }

    if (player->pos.x >= 80 || player->pos.x < 0) {
        player->vel.x *= -1;
    }

    // player->vel.x += TotalForce(player).x;
    // player->vel.y += TotalForce(player).y;
}

int main(int argc, char const* argv[]) {
    Object2D* player =
        CreateObject2D(10.0f, (Vector2){0, 0}, (Vector2){0.07, 0.07});
    AddForce(player, (Vector2){0.0f, 0.01});
    int x = 0;
    while (x++ < 5000) {
        system("clear");
        update(player);
        Draw(player->pos);
    }
    return 0;
}
