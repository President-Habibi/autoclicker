#include <SDL3/SDL.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "gui.hpp"

using std::string;
using std::runtime_error;

namespace AutoclickerGUI
{
	GUI::GUI()
	{
		createWindow();
	}

	GUI::~GUI()
	{
		SDL_Quit();
	}

	void GUI::createWindow()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			string error = SDL_GetError();
			string errorMessage = "SDL_Init() failed: " + error;
			throw runtime_error(errorMessage);
		}

		SDL_DisplayID displayId = SDL_GetPrimaryDisplay();
		const SDL_DisplayMode* displayMode = SDL_GetCurrentDisplayMode(displayId);

		if (displayMode == nullptr)
		{
			string error = SDL_GetError();
			string errorMessage = "Failed to get display mode: " + error;
			throw runtime_error(errorMessage);
		}

		const int screenWidth = displayMode->w;
		const int screenHeight = displayMode->h;

		SDL_Window* window = SDL_CreateWindow("MC Autoclicker", screenWidth / 2, screenHeight / 2, SDL_WINDOW_RESIZABLE);
		if (window == nullptr)
		{
			string error = SDL_GetError();
			string errorMessage = "SDL_Window creation failed: " + error;
			throw runtime_error(errorMessage);
		}

		SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
		if (renderer == nullptr)
		{
			string error = SDL_GetError();
			string errorMessage = "SDL_Renderer creation failed: " + error;
			SDL_DestroyWindow(window);
			SDL_Quit();
			throw runtime_error(errorMessage);
		}

		bool running = true;
		SDL_Event event;
		float menuX = 0, menuY = 0;

	}
}