#include "Game.h"
#include "AssetManager.h"
#include "Splash.h"

int main()
{
	Game game;
	AssetManager manger;
	game.pushState(new SplashScreenState(&game));
	game.gameLoop();
}