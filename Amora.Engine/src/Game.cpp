#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>
#include "Game.h"

Game::Game() {
	window_width = 800;
	window_height = 600;
	is_running = false;
	mRenderer = NULL;
	mWindow = NULL;
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

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	window_width = 800;
	window_height = 600;
	mWindow = SDL_CreateWindow(
		NULL, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		window_width, 
		window_height, 
		SDL_WINDOW_BORDERLESS);
	if (!mWindow)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN);

	is_running = true;
}

void Game::run() {
	setup();
	while (is_running)
	{
		process_input();
		update();
		render();
	}
}

void Game::process_input() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				is_running = false;
			}
		}
	}
}

glm::vec2 playerPosition;
glm::vec2 playerVelocity;

void Game::setup() {
	playerPosition = glm::vec2(10, 20);
	playerVelocity = glm::vec2(0.5, 0.0);
}

void Game::update() {
	playerPosition.x += playerVelocity.x;
	playerPosition.y += playerVelocity.y;
}

void Game::render() {
	SDL_SetRenderDrawColor(mRenderer, 21, 21, 21, 255);
	SDL_RenderClear(mRenderer);

	// Load a PNG texture 
	SDL_Surface* surface = IMG_Load(".\\assets\\images\\tank-tiger-right.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect dstRect = { 
		static_cast<int>(playerPosition.x), 
		static_cast<int>(playerPosition.y),
		32, 
		32 
	};

	SDL_RenderCopy(mRenderer, texture, NULL, &dstRect);
	
	SDL_RenderPresent(mRenderer);
}

void Game::destroy() {
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
}