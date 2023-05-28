#include <libspichki/gamelib.h>

char* waitInput(char* str)
{
    int q = 0;
    __fpurge(stdin);
    for (q = 0; (str[q] = getchar()) != '\n'; q++)
        ;
    str[q] = '\n';
    if (str[0] == 'q' && str[1] == '\n') {
        system("clear");
        exit(0);
    }
    return str;
}

heap* getPiles(char* count)
{
    int pile_count = 3;
    heap* pile_status = (heap*)calloc(pile_count, sizeof(heap));
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    int num = 0;
    int v = 0;

    while (count[v] != '\n') {
        if ((count[v] < '0') || (count[v] > '9')) {
            v = -1;

            return NULL;
        }
        v++;
    }
    num = atoi(count);
    if (num <= 0) {
        return NULL;
    }
    if (num > 0) {
        for (int i = 0; i < pile_count; i++)
            pile_status[i].stock = num;
    }
    return pile_status;
}

void interface(heap* pile_status, char playername)
{
    system("clear");
    printf(" [Для выхода нажмите q] \n");
    printf("|");
    for (int i = 0; i < 3; i++) {
        if (pile_status[i].stock != 0)
            printf(" %c%d |", pile_status[i].name, pile_status[i].stock);
    }
    printf("\nХод игрока %c\n", playername);
}

void errorPrint(int code, heap* pile_status, char playername)
{
    switch (code) {
    case FORMAT_ERR:
        system("clear");
        interface(pile_status, playername);
        printf("\nВы не можете забрать меньше одной спички, повторите "
               "попытку: ");
        break;
    case COUNT_ERR:
        system("clear");
        interface(pile_status, playername);
        printf("\nВы не можете забрать меньше одной спички, повторите "
               "попытку: ");
        break;
    case HEAP_ERR:
        system("clear");
        interface(pile_status, playername);
        printf("\nТакой кучи нет, повторите попытку: ");
        break;
    case SHUTDOWN:
        exit(0);
    default:
        system("clear");
    }
}

int errorCheck(char* strPile, heap* pile_status)
{
    int i = 1;
    int num = 0;
    if (strPile[0] == 'q' && strPile[1] == '\n')
        return SHUTDOWN;

    if ((toupper(strPile[0]) < 65) || (toupper(strPile[0]) > 90)) {
        return FORMAT_ERR;
    }
    if (((toupper(strPile[0]) != 'A') || (pile_status[0].stock <= 0))
        && ((toupper(strPile[0]) != 'B') || (pile_status[1].stock <= 0))
        && ((toupper(strPile[0]) != 'C') || pile_status[2].stock <= 0)) {
        if ((toupper(strPile[0]) > 67) && (toupper(strPile[0]) < 91))

            return HEAP_ERR;
        else

            return FORMAT_ERR;
    }
    while (strPile[i] == ' ')
        i++;
    if ((strPile[i] == '-')) {
        return COUNT_ERR;
    }
    while (strPile[i] == '0' && num == 0) {
        i++;
        if (strPile[i] == '\n') {
            return COUNT_ERR;
        }
        if (((strPile[i] >= '1') && (strPile[i] <= '9')))
            continue;
    }
    while (((strPile[i] >= '1') && (strPile[i] <= '9'))
           || ((strPile[i] == '0') && (num == 1))) {
        num = 1;
        i++;
    }
    if ((strPile[i] == '-') && (num == 1)) {
        return FORMAT_ERR;
    }

    if (((strPile[i] < '0') || (strPile[i] > '9')) && (num == 1)
        && (strPile[i] != '\n')) {
        return FORMAT_ERR;
    }
    if (num == 0) {
        return FORMAT_ERR;
    }
    if (strPile[i] == '\n') {
        return 0;
    }
    return 0;
}

player* getData(char* strPile)
{
    player* move = (player*)calloc(1, sizeof(player));
    char number[MAXSTR] = {};
    int j = 0;
    strPile[0] = toupper(strPile[0]);
    move->nameOfPile = strPile[0];
    for (int i = 1; i <= (int)strlen(strPile); i++) {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    move->countOfItems = atoi(number);

    return move;
}

void game(char* str, heap* pile_status)
{
    player* move = getData(str);
    for (int i = 0; i <= 3; i++) {
        if (move->nameOfPile == pile_status[i].name)
            pile_status[i].stock -= move->countOfItems;
    }
    for (int i = 0; i <= 3; i++)
        if (pile_status[i].stock < 0)
            pile_status[i].stock = 0;
    free(move);
}
