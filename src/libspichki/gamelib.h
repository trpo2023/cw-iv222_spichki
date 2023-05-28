#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 255
#define FORMAT_ERR -1
#define COUNT_ERR -2
#define HEAP_ERR -3
#define SHUTDOWN 1

struct heap {
    char name;
    int stock;
};
/* Структура которая хранит название кучи и количество предметов в ней. Будет
 хранить актуальные данные о кучах*/
typedef struct heap heap;

struct player {
    char nameOfPile;
    int countOfItems;
};
/* Структура которая хранит название кучи и количество предметов в ней. Данные
 из этой структуры получены от игрока и используются только для того, чтобы
 отнять нужное количество(countOfItems) из кучи(nameOfPile)*/
typedef struct player player;
/*Принимает массив символов, записывает в него значение с клавиатуры и
 * возвращает указатель на него*/
char* waitInput(char* str);

heap* getPiles(char* count);

void interface(heap* pile_status, char playername);

void errorPrint(int code, heap* pile_status, char playername);

int errorCheck(char* strPile, heap* pile_status);

player* getData(char* strPile);

void game(char* str, heap* pile_status);