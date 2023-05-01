#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxstr 255

struct heap
{
    char name;
    int stock;
};
typedef struct heap heap;

struct player
{
    char nameOfPile;
    int countOfItems;
};
typedef struct player player;

heap* getPiles();

player* getPlayerPile();
