#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "libs/entity.h"
#include "libs/constants.h"
#include "libs/utils.h"

/**
 * ==============================
 * ====== WRAPPER FUNCTION ======
 */

void scc(int code){
    if(code < 0){
        printf("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return;
}

void *scp(void *ptr){
    if(ptr == NULL){
        printf("SDL Error: %s", SDL_GetError());
        exit(1);
    }
    return ptr;
}

/**
 * ==============================
 * ====== RANDOM FUNCTION =======
 */

Position getRandomPosition(){
    int x = getRandomInt(0, SCREEN_WIDTH);
    int y = getRandomInt(0, SCREEN_HEIGTH);

    Position newPosition = {x, y};
    return newPosition;
}

int getRandomInt(int min, int max) { 
    return rand() % (max + 1 - min) + min; 
}

float getRandomFloat(float min, float max) { 
    return min + ((float)rand() / RAND_MAX) * (max - min); 
}

/**
 * ==============================
 * ====== MATH FUNCTION =======
 */

float getAngularCoefficient(Position* point1, Position* point2) {
    return ((float)(point2->y - point1->y) / (float)(point2->x - point1->x));
}

/**
 * ==============================
 * ====== CREATION FUNCTION =======
 */

Position* createPosition(int x, int y) {
    Position *newPos = malloc(sizeof(Position));
    if(newPos == NULL){
        printf("Memory full");
        exit(1);
    }
    newPos->x = x;
    newPos->y = y;
    return newPos;
}
