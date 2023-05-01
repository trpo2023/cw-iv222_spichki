#include <libspichki/gamelib.h>

heap* getPiles()
{
    int pile_count = 3; // Количество куч
    heap* pile_status = (heap*)calloc(
            pile_count,
            sizeof(heap)); // Динамически выделяю память под массив структур куч
    char strPile[maxstr] = " "; // Сюда пойдет вся строка с ввода
    char number[maxstr] = {}; // Сюда пойдут только числа после первой буквы
    int j = 0;
    for (int i = 0; i < pile_count; i++) {
        printf("Задайте %d-ю кучу (пример:B35): ", i + 1);
        scanf("%s", strPile);
        pile_status[i].name = toupper(
                strPile[0]); // Записываю имя кучи из строки в структуру
        for (int i = 1; i <= (int)strlen(strPile);
             i++) // Весь этот for чтобы скопировать из строки число в number
        {
            number[j] = strPile[i];
            j++;
        }
        j = 0;
        pile_status[i].stock
                = atoi(number); /* Приводим число из строки number в тип int и
                                 записываем в структуру */
        printf("\n");
    }
    return pile_status;
}

player* getPlayerPile()
{
    player* move = (player*)calloc(
            1,
            sizeof(player)); /* Выделяю память для структуры, в которую запишу
                              данные в нужной форме, считанные с клавиатуры*/
    char strPile[maxstr] = ""; /* Объявляю строку, в которой будет хранится
                                считанная с клавы строка*/
    char number[maxstr] = {}; /* Объявляю строку, куда буду помещать число
                               написанное строкой*/
    int j = 0; // Счетчик для прохождения по number
    scanf("%s", strPile);
    strPile[0] = toupper(strPile[0]); /* Корректируем ввод на случай, если куча
                                       была написана с маленькой буквы*/
    move->nameOfPile = strPile[0]; // Вытаскиваем из строки имя кучи
    for (int i = 1; i <= (int)strlen(strPile); // Записываю число из строки в number
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
        printf("| %c%d | %c%d | %c%d |\n",
               pile_status[0].name,
               pile_status[0].stock,
               pile_status[1].name,
               pile_status[1].stock,
               pile_status[2].name,
               pile_status[2].stock); /* Этот страшный printf выводит все
                                       имеющиеся кучи*/
        printf("Ход игрока %c\n", playername);
        player* move = getPlayerPile(); // Здесь игрок пишет с клавиатуры кучу
        for (int i = 0; i <= 3; i++) {
            if (move->nameOfPile == pile_status[i].name)
                pile_status[i].stock -= move->countOfItems;
        } // В цикле выше если совпало имя, то отнимаем нужное кол-во предметов
        for (int i = 0; i <= 3; i++) // Обнуляем кучу, если ушли в минус
            if (pile_status[i].stock < 0)
                pile_status[i].stock = 0;
        free(move);
    }
    printf("\nПобеда игрока %c\n", playername); // Кучи кончились, игрок победил
}