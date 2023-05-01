#include <libspichki/gamelib.h>

heap* getPiles()
{
    int pile_count = 3;                                                 // Количество куч
    heap * pile_status = (heap *) calloc(pile_count, sizeof(heap));     // Динамически выделяю память под массив структур куч
    char strPile[maxstr] = " ";                                         // Сюда пойдет вся строка с ввода
    char number[maxstr] = {};                                           // Сюда пойдут только числа после первой буквы
    int j = 0;
    for (int i = 0;i<pile_count;i++)
    {
        printf("Задайте %d-ю кучу (пример:B35): ",i+1);
        scanf("%s",strPile);
        pile_status[i].name = toupper(strPile[0]);                               // Записываю имя кучи из строки в структуру
        for (int i = 1;i<=strlen(strPile);i++)                          // Весь этот for чтобы скопировать из строки число в number
        {
            number[j] = strPile[i];
            j++;
        }
        j = 0;
        pile_status[i].stock = atoi(number);                            // Приводим число из строки number в тип int и записываем в структуру
    printf("\n");
    }
    return pile_status;
}

player* getPlayerPile()
{
    player * move = (player *) calloc(1, sizeof(player)); 
    char strPile[maxstr] = "";
    char number[maxstr] = {}; 
    int j = 0;
    scanf("%s",strPile);
    strPile[0] = toupper(strPile[0]);
    move->nameOfPile = strPile[0];
    for (int i = 1;i<=strlen(strPile);i++)                          
    {
        number[j] = strPile[i];
        j++;
    }
    j = 0;
    move->countOfItems = atoi(number);    

    return move;
}