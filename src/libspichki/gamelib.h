#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxstr 255
/* Структура которая хранит название кучи и количество предметов в ней. Будет
 хранить актуальные данные о кучах*/
struct heap {
    char name;
    int stock;
};
typedef struct heap heap;


struct player {
    char nameOfPile;
    int countOfItems;
};
/* Структура которая хранит название кучи и количество предметов в ней. Данные
 из этой структуры получены от игрока и используются только для того, чтобы
 отнять нужное количество(countOfItems) из кучи(nameOfPile)*/
typedef struct player player;
/*Функция запрашивает с игрока название куч и количество предметов в них.
 * Возвращает массив куч*/
heap* getPiles();
/*Функция запрашивает с игрока кучу и количество предметов, которые тот хочет
 * забрать. Возвращает кучу*/
player* getPlayerPile();
/*!ВРЕМЕННО! Функция работает как интерфейс, так и реализация игрового процесса,
 * принимает на вход массив куч*/
void game(heap* pile_status);