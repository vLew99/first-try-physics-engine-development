#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamics.h"
#include "vector_funcs.h"

#define TICKS_PER_SECOND 60
#define SKIP_TICKS 1000 / TICKS_PER_SECOND

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define OBJECT_WIDTH 20
#define OBJECT_HEIGHT 20
#define USERINPUT_SIZE 3

#define HORIZONTAL_SPEED 1.0
#define VERTICAL_SPEED 1.5

#define GRAVITY 0.98

typedef struct {
    SDL_Renderer* rend;
    SDL_Window* wind;
    bool running;
    bool* user_input;
    SDL_Event e;
    Object2D* player;
} Game;

bool onInit(Game* game) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return false;
    }
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &game->wind,
                                    &game->rend) != 0) {
        return false;
    }
    SDL_RenderSetVSync(game->rend, 1);
    return true;
}

bool initializePlayer(Game* game) {
    game->user_input = (bool*)malloc(sizeof(bool) * USERINPUT_SIZE);
    game->player = CreateObject2D(10.0f, (Vector2){200, 400}, (Vector2){0, 0});

    AddForce(game->player, (Vector2){0, GRAVITY});
    AddImpulse(game->player, (Vector2){10, -10});
    return true;
}

void onInput(Game* game) {
    while (SDL_PollEvent(&game->e)) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        if (game->e.type == SDL_QUIT) {
            game->running = false;
        }
        if (keystates[SDL_SCANCODE_Q] || keystates[SDL_SCANCODE_ESCAPE]) {
            game->running = false;
        }
        game->user_input[2] = keystates[SDL_SCANCODE_SPACE];
        game->user_input[0] =
            keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_LEFT];
        game->user_input[1] =
            keystates[SDL_SCANCODE_D] || keystates[SDL_SCANCODE_RIGHT];
    }
}

void onUpdate(Game* game, Uint32 dt) {
    // changing velocity for each input
    // TODO: If a force is applied it does not stop because there is no gravity,
    // that makes the object go on and on horizontally

    ApplyForces(game->player);
    ApplyImpulses(game->player);

    int8_t user_vel =
        (game->user_input[1] - game->user_input[0]) * HORIZONTAL_SPEED * dt;
    /* printf("user_vel %d\n", user_vel); */

    if (user_vel != 0) {
        game->player->vel.x = user_vel;
    }

    if (game->user_input[2]) {
        game->player->vel.y = -VERTICAL_SPEED * dt;
        game->user_input[2] = 0;
    }

    // changes in velocity

    /* player->vel.x += userInput.x; */
    /* player->vel.y += userInput.y; */

    Vector2 temp = AddV2(game->player->pos, game->player->vel);

    if (temp.y < 0 || temp.y > WINDOW_HEIGHT - OBJECT_HEIGHT) {
        game->player->vel.y *= -0.3;
    } else {
        game->player->pos.y = temp.y;
    }

    if (temp.x < 0 || temp.x > WINDOW_WIDTH - OBJECT_WIDTH) {
        game->player->vel.x = 0;
    } else {
        game->player->pos.x = temp.x;
    }

    // change in position

    /* LL_PrintForward(&player->force_list); */
    /* RemoveForce(player, (Vector2){0, -2}); */
    /* printf("Player position -> %f, %f \n", player->pos.x, player->pos.y);
     */
    /* printf("Player velocity -> %f, %f \n", player->vel.x, player->vel.y);
     */
}

void onCleanUp(SDL_Window* wind, SDL_Renderer* rend) {
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
    SDL_Quit();
}

void onRender(Game* game) {
    // drawing the background
    SDL_SetRenderDrawColor(game->rend, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(game->rend);

    SDL_SetRenderDrawColor(game->rend, 0xff, 0xff, 0xff, 255);
    SDL_FRect tempRect = (SDL_FRect){.h = OBJECT_HEIGHT,
                                     .w = OBJECT_WIDTH,
                                     .x = game->player->pos.x,
                                     .y = game->player->pos.y};
    SDL_RenderFillRectF(game->rend, &tempRect);

    // present everything at the last
    SDL_RenderPresent(game->rend);
}

int main(void) {
    Game game = {.wind = NULL,
                 .rend = NULL,
                 .running = true,
                 .user_input = NULL,
                 .player = NULL};

    if (onInit(&game) == false) exit(-1);

    // as we want to change the value of the pointer (the address it points to)
    // when memory allocation is done, therefore we must pass pointer to
    // poiinter as function argument. Passing only one pointer can only change
    // the value of address this pointer points to
    initializePlayer(&game);

    Uint32 last_frame_time = 0;
    Uint32 curr_time, delta_time;

    while (game.running) {
        curr_time = SDL_GetTicks();
        delta_time = curr_time - last_frame_time;
        onInput(&game);
        onUpdate(&game, delta_time);
        onRender(&game);
        last_frame_time = curr_time;
    }

    free(game.user_input);
    DeleteObject2D(game.player);
    onCleanUp(game.wind, game.rend);
    return 0;
}
