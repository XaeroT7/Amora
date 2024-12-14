#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>
#include "Game.h"
#include "../ECS/ECS.h"
#include "../Logger/Logger.h"

Game::Game() {
	is_running = false;
	Logger::log("Game constructor called!");
}

Game::~Game() {
	Logger::log("Game destructor called!");
}

void Game::initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Logger::log_error("Error initialize SDL: " + std::string(SDL_GetError()));
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
		Logger::log_error("Error creating SDL window: " + std::string(SDL_GetError()));
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		Logger::log_error("Error creating SDL renderer: " + std::string(SDL_GetError()));
		return;
	}
	
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

void Game::setup() {
	// TODO:
	// Entity tank = registry.create_entity();
	// tank.add_component<TransformComponent>();
	// tank.add_component<BoxColliderComponent>();
	// tank.add_component<SpriteComponent>("./assets/images/tank.png");
}

void Game::update() {
	int time_to_wait = MILLISECONDS_PER_FRAME - (SDL_GetTicks() - milliseconds_previous_frame);
	if (time_to_wait > 0 && time_to_wait <= MILLISECONDS_PER_FRAME) {
		SDL_Delay(time_to_wait);
	}

	double deltaTime = (SDL_GetTicks() - milliseconds_previous_frame) / 1000.0;

	// Store the current frame time
	milliseconds_previous_frame = SDL_GetTicks();

	// TODO:
	// MovementSystem.Update();
	// CollisionSystem.Update();
	// DamageSystem.Update();
}

void Game::render() {
	SDL_SetRenderDrawColor(mRenderer, 21, 21, 21, 255);
	SDL_RenderClear(mRenderer);

	// TODO: Render game objects...
	
	SDL_RenderPresent(mRenderer);
}

void Game::destroy() {
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
}