#include "Game.h"
int main()
{
    Game* game = new Game();
    game->setup();
    game->gameLoop();
}