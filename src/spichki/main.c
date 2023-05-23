#include <libspichki/gamelib.h>

int main()
{
    char str[MAXSTR];
    char* s;
    heap* pile_status;
    printf("Сколько должно быть предметов в куче?: ");
    do {
        s = waitInput(str);
        pile_status = getPiles(s);
    } while (pile_status == NULL);
    game(pile_status);
    free(pile_status);
    return 0;
}