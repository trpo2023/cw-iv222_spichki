#include <ctest.h>
#include <libspichki/gamelib.h>

#define CTEST_SEGFAULT
#define CTEST_COLOR_OK

CTEST(TEST_Input_count_1, getPiles)
{
    char str[] = "abcdf";
    ASSERT_EQUAL(NULL, getPiles(str));
}

CTEST(TEST_Input_count_2, getPiles)
{
    char str[] = "-1";
    ASSERT_EQUAL(NULL, getPiles(str));
}

CTEST(TEST_Input_count_3, getPiles)
{
    int pile_count = 3;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    pile_status[0].stock = 30;
    pile_status[1].stock = 30;
    pile_status[2].stock = 30;
    char str[] = "30";
    ASSERT_EQUAL(NULL, getPiles(str));
    free(pile_status);
}

CTEST(TEST_PLAYER_INPUT_1, errorCheck)
{
    int pile_count = 3;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    pile_status[0].stock = 30;
    pile_status[1].stock = 30;
    pile_status[2].stock = 30;
    char str[] = "kd";
    ASSERT_EQUAL(NULL, errorCheck(str, pile_status));
    free(pile_status);
}

CTEST(TEST_PLAYER_INPUT_2, errorCheck)
{
    int pile_count = 2;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[0].stock = 30;
    pile_status[1].stock = 30;
    char str[] = "C35";
    ASSERT_EQUAL(NULL, errorCheck(str, pile_status));
    free(pile_status);
}

CTEST(TEST_PLAYER_INPUT_3, errorCheck)
{
    int pile_count = 3;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    pile_status[0].stock = 30;
    pile_status[1].stock = 30;
    pile_status[2].stock = 30;
    char str[] = "a-28";
    ASSERT_EQUAL(NULL, errorCheck(str, pile_status));
    free(pile_status);
}

CTEST(TEST_PLAYER_INPUT_4, errorCheck)
{
    int pile_count = 3;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    pile_status[0].stock = 30;
    pile_status[1].stock = 30;
    pile_status[2].stock = 30;
    char str[] = "A28\n";
    ASSERT_STR(str, errorCheck(str, pile_status));
    free(pile_status);
}

CTEST(TEST_HEAP_1, getData)
{
    char strPile[] = "c15";
    player* move = getData(strPile);
    ASSERT_EQUAL('C', move->nameOfPile);
}

CTEST(TEST_HEAP_2, getData)
{
    char strPile[] = "c15";
    player* move = getData(strPile);
    ASSERT_EQUAL(15, move->countOfItems);
}