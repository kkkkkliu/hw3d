#include <Windows.h>
#include <sstream>
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
		//if (wnd.kbd.KeyIsPressed(VK_MENU))
		//{
		//	MessageBox(nullptr, TEXT("Something Happen!"), TEXT("Space Key Was Pressed!"), MB_ICONERROR);
		//}

		while (!wnd.mouse.IsEmpty())
		{
			const auto e = wnd.mouse.Read();
			/*********************test mouse tap*******************************/
			//switch ((*e).GetType())
			//{
			//case Mouse::Event::Type::Leave: {
			//	wnd.SetTitle(L"Gone!");
			//	break;
			//}
			//case Mouse::Event::Type::Move: {
			//	std::wstringstream oss;
			//	oss << "Mouse Position: (" << (*e).GetPosX() << "," << (*e).GetPosY() << ")";
			//	wnd.SetTitle(oss.str());
			//	break;
			//}
			//}
			/*********************test mouse wheel*****************************/
			static int up = 0;
			static int down = 0;
			switch ((*e).GetType())
			{
			case Mouse::Event::Type::WheelUp: {
				up++;
				wnd.SetTitle(std::to_wstring(up));
				break;
			}
			case Mouse::Event::Type::WheelDown: {
				down--;
				wnd.SetTitle(std::to_wstring(down));
				break;
				break;
			}
			}
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