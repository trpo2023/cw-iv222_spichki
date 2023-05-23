#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 255

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
/*Функция инициализирует кучи и определяет количество предметов в них. Принимает
 * строку и проверяет ее на ошибки. Возвращает массив куч, если ошибок нет.
 * Возвращает NULL, если ошибки есть. */
heap* getPiles(char* count);
/*Принимает массив куч и выводит их*/
void interface(heap* pile_status);
/*Проверяет строку игрока на ошибки. Принимает указатель на массив символов и
 * массив куч. Возвращает строку, если ошибок нет. Возвращает NULL, если ошибки
 * есть.*/
char* errorCheck(char* strPile, heap* pile_status);
/*Функция разбивает строку на структуру кучи. Возвращает кучу*/
player* getData(char* strPile);
/*Реализация игрового процесса,
 * принимает на вход массив куч*/
void game(heap* pile_status);