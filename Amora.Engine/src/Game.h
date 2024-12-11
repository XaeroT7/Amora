#ifndef GAME_H
#define GAME_H

#include "SDL.h"

class Game {
private:
	bool is_running;
	SDL_Window *mWindow;
	SDL_Renderer* mRenderer;

public:
	Game();
	~Game();

	void initialize();
	void run();
	void process_input();
	void update();
	void render();
	void destroy();

	int window_width;
	int window_height;
};

#endif