#include <libspichki/gamelib.h>

int main()
{
    char str[MAXSTR];
    char* s;
    heap* pile_status;
    char playername = '1';
    int code = 10;
    printf("Сколько должно быть предметов в куче?: ");
    s = waitInput(str);
    pile_status = getPiles(s);
    while (pile_status == NULL) {
        system("clear");
        printf("Число задано не корректно, повторите попытку: ");
        s = waitInput(str);
        pile_status = getPiles(s);
    }

    while ((pile_status[0].stock + pile_status[1].stock + pile_status[2].stock)
           > 0) {
        interface(pile_status, playername);
        s = waitInput(str);
        while ((code = errorCheck(s, pile_status)) != 0) {
            errorPrint(code, pile_status, playername);
            s = waitInput(str);
        }
        game(s, pile_status);
        if (playername == '1')
            playername = '2';
        else
            playername = '1';
    }
    if (playername == '1')
        playername = '2';
    else
        playername = '1';
    system("clear");
    printf("\nПобеда игрока %c\n", playername); // Кучи кончились, игрок победил
    free(pile_status);
    return 0;
}