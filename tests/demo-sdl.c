#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "dynamics.h"
#include "types.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define OBJECT_WIDTH 10
#define OBJECT_HEIGHT 10
#define USERINPUT_SIZE 3

bool onInit(SDL_Window** wind, SDL_Renderer** rend) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return false;
    }
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, wind,
                                    rend) != 0) {
        return false;
    }
    return true;
}

bool initializePlayer(Object2D** player, int8_t** user_inputs) {
    *(user_inputs) = (int8_t*)malloc(sizeof(int8_t) * USERINPUT_SIZE);
    *(player) = CreateObject2D(10.0f, (Vector2){200, 400}, (Vector2){0, 0});

    // apply gravity
    AddForce(*player, (Vector2){0, 0.98});

    // impulse
    AddImpulse(*player, (Vector2){0, -1});
    return true;
}

void onInput(Object2D* player, SDL_Event* event, int8_t* user_input,
             bool* running) {
    while (SDL_PollEvent(event)) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        if (event->type == SDL_QUIT) {
            *running = false;
        }
        if (keystates[SDL_SCANCODE_Q]) {
            *running = false;
        }

        if (keystates[SDL_SCANCODE_SPACE]) {
            user_input[2] = 1;
        }
        if (keystates[SDL_SCANCODE_A]) {
            user_input[0] = -1;
        } else if (keystates[SDL_SCANCODE_D]) {
            user_input[0] = 1;
        } else {
            user_input[0] = 0;
            user_input[1] = 0;
        }
    }
}

void onUpdate(Object2D* player, int8_t* user_input) {
    // changing velocity for each input
    switch (user_input[0]) {
        case -1:
            player->vel.x = -5;
            break;
        case 1:
            player->vel.x = 5;
            break;
        case 0:
            player->vel.x = 0;
            break;
    }
    if (user_input[2] == 1) {
        /* AddImpulse(player, (Vector2){0, -10}); */
        player->vel.y = -10;
        /* AddImpulse(player, (Vector2){10, 0}); */
        /* AddForce(player, (Vector2){1, 0}); */
        user_input[2] = 0;
    }

    ApplyForces(player);
    ApplyImpulses(player);

    // changes in velocity

    /* player->vel.x += userInput.x; */
    /* player->vel.y += userInput.y; */

    if (player->pos.y + player->vel.y < 0) {
        player->pos.y = 0;
        player->vel.y = 0;
    } else if (player->pos.y + player->vel.y >= 0) {
        player->pos.y += player->vel.y;
    }
    if (player->pos.y + player->vel.y > WINDOW_HEIGHT - OBJECT_HEIGHT) {
        player->pos.y = WINDOW_HEIGHT - OBJECT_HEIGHT;
        player->vel.y *= -player->mass * 0.04;
    } else if (player->pos.y + player->vel.y <= WINDOW_HEIGHT - OBJECT_HEIGHT) {
        player->pos.y += player->vel.y;
    }

    if (player->pos.x + player->vel.x < 0) {
        player->pos.x = 0;
        player->vel.x = 0;
    } else if (player->pos.x + player->vel.x >= 0) {
        player->pos.x += player->vel.x;
    }

    if (player->pos.x + player->vel.x > WINDOW_WIDTH - OBJECT_WIDTH) {
        player->pos.x = WINDOW_WIDTH - OBJECT_WIDTH;
        player->vel.x = 0;
    } else if (player->pos.x + player->vel.x <= WINDOW_WIDTH - OBJECT_WIDTH) {
        player->pos.x += player->vel.x;
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

void onRender(SDL_Renderer* rend, Object2D* player) {
    // drawing the background
    SDL_SetRenderDrawColor(rend, 0x11, 0x11, 0x11, 244);
    SDL_RenderClear(rend);

    SDL_Delay(1000 / 100);

    SDL_SetRenderDrawColor(rend, 0xff, 0xff, 0xff, 255);
    SDL_FRect tempRect = (SDL_FRect){.h = OBJECT_HEIGHT,
                                     .w = OBJECT_WIDTH,
                                     .x = player->pos.x,
                                     .y = player->pos.y};
    SDL_RenderFillRectF(rend, &tempRect);

    // present everything at the last
    SDL_RenderPresent(rend);
}

int main(void) {
    SDL_Window* wind;
    SDL_Renderer* rend;

    Object2D* player;
    int8_t* user_input;
    SDL_Event e;

    if (onInit(&wind, &rend) == false) exit(-1);

    // as we want to change the value of the pointer (the address it points to)
    // when memory allocation is done, therefore we must pass pointer to
    // poiinter as function argument. Passing only one pointer can only change
    // the value of address this pointer points to
    initializePlayer(&player, &user_input);

    bool running = true;

    while (running) {
        onInput(player, &e, user_input, &running);
        onUpdate(player, user_input);
        onRender(rend, player);
    }

    free(user_input);
    DeleteObject2D(player);
    onCleanUp(wind, rend);
    return 0;
}
