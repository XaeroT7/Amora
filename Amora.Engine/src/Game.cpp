#include <iostream>
#include "SDL.h"
#include "Game.h"

Game::Game() {
	// TODO:...
	std::cout << "Game constructor called!" << std::endl;
}

Game::~Game() {
	std::cout << "Game destructor called!" << std::endl;
}

void Game::initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Window *window = SDL_CreateWindow(
		NULL, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		800, 
		600, 
		SDL_WINDOW_BORDERLESS);
	if (!window)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
		return;
	}
}

void Game::run() {
	while (true)
	{
		process_input();
		update();
		render();
	}
}

void Game::process_input() {

}

void Game::update() {

}

void Game::render() {

}

void Game::destroy() {

}