#include <libspichki/gamelib.h>

void waitInput(char* str)
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
}

heap* getPiles()
{
    int pile_count = 3; // Количество куч
    heap* pile_status = (heap*)calloc(
            pile_count,
            sizeof(heap)); // Динамически выделяю память под массив структур куч
    pile_status[0].name = 'A';
    pile_status[1].name = 'B';
    pile_status[2].name = 'C';
    char count[MAXSTR];
    int num = 0;
    int v = 0;
    printf("Сколько должно быть предметов в куче?: ");
    int err = 0;
    while (err == 0) {
        system("clear");
        waitInput(count);
        printf("%s", count);
        while (count[v] != '\n') {
            if ((count[v] < '0') || (count[v] > '9')) {
                v = -1;
                system("clear");
                printf("Число задано не корректно, повторите попытку: ");
                waitInput(count);
            }
            v++;
        }
        num = atoi(count);
        if (num == 0) {
            printf("Число задано не корректно, повторите попытку: ");
            err = 0;
        }
        if (num < 0) {
            printf("Число должно быть больше нуля и при этом не превышать "
                   "максимальное значение(1874919423), повторите попытку: ");
            err = 0;
        }
        if (num > 0)
            err = 1;
    }
    num = atoi(count);

    for (int i = 0; i < pile_count; i++)
        pile_status[i].stock = num;
    return pile_status;
}

void interface(heap* pile_status)
{
    system("clear");
    printf(" [Для выхода нажмите q] \n");
    printf("|");
    for (int i = 0; i < 3; i++) {
        if (pile_status[i].stock != 0)
            printf(" %c%d |", pile_status[i].name, pile_status[i].stock);
    }
    printf("\n");
}

player* getData(char* strPile)
{
    player* move = (player*)calloc(
            1,
            sizeof(player)); /* Выделяю память для структуры, в которую запишу
                              данные в нужной форме, считанные с клавиатуры*/
    char number[MAXSTR] = {}; /* Объявляю строку, куда буду помещать число
                               написанное строкой*/
    int j = 0; // Счетчик для прохождения по number
    strPile[0] = toupper(strPile[0]); /* Корректируем ввод на случай, если куча
                                       была написана с маленькой буквы*/
    move->nameOfPile = strPile[0]; // Вытаскиваем из строки имя кучи
    for (int i = 1;
         i <= (int)strlen(strPile); // Записываю число из строки в number
         i++) {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    move->countOfItems = atoi(number); /* Перевожу число строкой в тип int и
                                        записываю ее в кучу move*/

    return move; /* Здесь move это та же куча, что и в pile_status, но созданная
                  конкретно как единичная куча, которую ввел игрок.*/
}

void game(heap* pile_status)
{
    char strPile[MAXSTR]; /* Объявляю строку, в которой будет хранится
                                считанная с клавы строка*/
    char* str;
    char playername
            = '2'; /* playername - имя текущего игрока. Начинаю со второго, т.к
                    в начале цикла буду делать переход на следующего игрока.*/
    while ((pile_status[0].stock + pile_status[1].stock
            + pile_status[2].stock) /* В этом огромном цикле, который, спасибо
                                     кленг-формату, превратился в белеберду,
                                     идет игра, пока все кучи не закончатся*/
           > 0) {
        if (playername == '1') // Здесь меняется игрок
            playername = '2';
        else
            playername = '1';

        interface(pile_status);
        printf("Ход игрока %c\n", playername);
        str = errorCheck(strPile, pile_status);
        player* move = getData(str); // Здесь игрок пишет с клавиатуры кучу
        for (int i = 0; i <= 3; i++) {
            if (move->nameOfPile == pile_status[i].name)
                pile_status[i].stock -= move->countOfItems;
        } // В цикле выше если совпало имя, то отнимаем нужное кол-во предметов
        for (int i = 0; i <= 3; i++) // Обнуляем кучу, если ушли в минус
            if (pile_status[i].stock < 0)
                pile_status[i].stock = 0;
        free(move);
    }
    system("clear");
    printf("\nПобеда игрока %c\n", playername); // Кучи кончились, игрок победил
}