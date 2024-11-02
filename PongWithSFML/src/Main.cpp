#ifdef _WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "../classes/Game.h"

int main() {
	Game game;
	game.Run();

	return 0;
}