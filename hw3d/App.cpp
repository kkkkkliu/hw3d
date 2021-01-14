#include "App.h"

App::App() :
	wnd(800,600,TEXT("3D Window")) { }

int App::Go() {
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage( &msg,nullptr,0,0)) > 0 )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	if (gResult == -1)
	{
		throw std::exception();
	}

	return msg.wParam;
}

void App::DoFrame() {

}