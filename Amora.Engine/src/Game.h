#ifndef GAME_H
#define GAME_H

class Game {
private:

public:
	Game();
	~Game();

	void initialize();
	void run();
	void process_input();
	void update();
	void render();
	void destroy();
};

#endif // GAME_H