#include "Game.h"
#include "Entities/Characters/Hero/Hero.h"
int main()
{
    Game* game = new Game();
    game->setup();
    game->gameLoop();
}