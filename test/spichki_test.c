#include <ctest.h>
#include <libspichki/gamelib.h>

#define CTEST_SEGFAULT
#define CTEST_COLOR_OK

CTEST(TEST_Input, name_input)
{
    char strPile[] = "b110";
    char name;
    name = toupper(strPile[0]);
    ASSERT_EQUAL('B', name);
}

CTEST(TEST_Input, number_input)
{
    char strPile[] = "b110";
    char number[maxstr] = {};
    int stock = 0;
    int j = 0;
    for (int i = 1; i <= strlen(strPile); i++) {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    stock = atoi(number);
    ASSERT_EQUAL(110, stock);
}

CTEST(TEST_Input, full_input)
{
    char strPile[] = "b110";
    char number[maxstr] = {};
    char name;
    int stock = 0;
    int j = 0;
    int real = 0;
    name = toupper(strPile[0]);
    for (int i = 1; i <= strlen(strPile); i++) {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    stock = atoi(number);
    if (name == 'B' && stock == 110)
        real = 1;
    ASSERT_EQUAL(1, real);
}

CTEST(TEST_Player, scan_player_heap)
{
    player* move = (player*)calloc(1, sizeof(player));
    char strPile[] = "c15";
    strPile[0] = toupper(strPile[0]);
    move->nameOfPile = strPile[0];
    ASSERT_EQUAL(strPile[0], move->nameOfPile);
    free(move);
}

CTEST(TEST_Player, scan_player_items)
{
    player* move = (player*)calloc(1, sizeof(player));
    char strPile[] = "c15";
    char number[maxstr] = {};
    int j = 0;
    for (int i = 1; i <= strlen(strPile); i++) {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    move->countOfItems = atoi(number);
    ASSERT_EQUAL(15, move->countOfItems);
    free(move);
}