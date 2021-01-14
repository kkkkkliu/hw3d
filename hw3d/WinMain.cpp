#include <Windows.h>
#include "App.h"
#include"Window.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow) 
{
	try
	{
		return App().Go();
	}
	catch (const std::exception&)
	{
	}
}