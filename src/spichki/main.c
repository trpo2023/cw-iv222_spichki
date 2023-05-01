#include <libspichki/gamelib.h>

int main()
{
    heap* pile_status = getPiles();
    game(pile_status);
    free(pile_status);
    return 0;
}