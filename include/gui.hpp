#ifndef GUI_HPP
#define GUI_HPP
#include <SDL3/SDL.h>

namespace AutoclickerGUI
{

	class GUI
	{
	public:
		GUI();
		~GUI();

	private:
		void createWindow();
	};

	struct Button
	{
		SDL_FRect rect;
		SDL_Color color;
	};

	

}

#endif