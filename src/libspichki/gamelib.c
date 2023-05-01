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
