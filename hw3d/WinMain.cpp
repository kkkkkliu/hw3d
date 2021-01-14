#include <Windows.h>
#include"Window.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow) 
{
	Window wnd(800, 300, TEXT("3D Window"));
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg,nullptr,0,0))>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (wnd.kbd.KeyIsPressed(VK_MENU))
		{
			MessageBox(nullptr, TEXT("Something Happen!"), TEXT("Space Key Was Pressed!"), MB_ICONERROR);
		}
	}
	if (gResult == -1)
	{
		return -1;
	}
	else {
		return msg.wParam;
	}
}