#ifndef GAME_H
#define GAME_H

#include <SDL.h>

const int FPS = 60;
const int MILLISECONDS_PER_FRAME = 1000 / FPS;

class Game {
private:
	bool is_running;
	SDL_Window *mWindow;
	SDL_Renderer* mRenderer;
	int milliseconds_previous_frame;

public:
	Game();
	~Game();

	void initialize();
	void run();
	void setup();
	void process_input();
	void update();
	void render();
	void destroy();

	int window_width;
	int window_height;
};

#endif