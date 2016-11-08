#include "Game.h"
#include "AssetManager.h"
#include "Splash.h"
#include "Menu.h"
int main()
{
	Game game;
	AssetManager manger;
	game.pushState(new Menu(&game));
	game.gameLoop();
}