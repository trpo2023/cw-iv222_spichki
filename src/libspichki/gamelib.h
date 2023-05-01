#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxstr 255

struct heap {
    char name;
    int stock;
};
typedef struct heap heap;

struct player {
    char nameOfPile;
    int countOfItems;
};
typedef struct player player;

heap* getPiles();

player* getPlayerPile();

void game(heap* pile_status);