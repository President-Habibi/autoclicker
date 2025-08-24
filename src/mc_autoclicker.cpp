#include "mc_autoclicker.hpp"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <cmath>

using std::cout, std::cin, std::endl; std::string;

void startAutoclicker()
{
	int cps;
	double toleranceRange;
	double millisecondsPerClick;

	cout << "Set the CPS: ";
	cin >> cps;
	cout << "Set the tolerance range: ";
	cin >> toleranceRange;
	cout << "Your selected settings: \nCPS: " << cps << "\nTolerance range: " << toleranceRange
		<< "\n\nTo stop this program, either press \\ on your keyboard (the backslash key), or close this console window." << endl;

	millisecondsPerClick = 1 / cps * 1000;

	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dx = 0;
	input.mi.dy = 0;
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	input.mi.time = 0;
	input.mi.dwExtraInfo = 0;
	
	while (true)
	{
		// left mouse button is being held down
		while ((GetAsyncKeyState(0x41) & 0x8000) != 0)
		{
			cout << "debug\n";

			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(500.0 / cps)));
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(500.0 / cps)));
		}

		// backslash was hit (i.e, user exits the program)
		if ((GetAsyncKeyState(VK_OEM_5) & 0x8000) != 0)
		{
			cout << "Closing the autoclicker..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return;
		}
	}
}
