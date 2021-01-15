#include "App.h"

App::App() :
	wnd(800,600,TEXT("3D Window")) { }

int App::Go() {
	while (true)
	{
		if (const auto ecode = Window::ProcessMessage()) {
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame() {
	//const float t = timer.Peek();
	//std::wostringstream oss;
	//oss << std::setprecision(1)<<std::fixed<<t;
	//wnd.SetTitle(oss.str());
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c,c,1.0f);
	wnd.Gfx().EndFrame();
}