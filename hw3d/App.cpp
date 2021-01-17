#include "App.h"
#include "Box.h"
#include <memory>

App::App() :
	wnd(800,600,TEXT("3D Window")) {
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> adist(0.0f, 3.1415f * 2.0f);
	std::uniform_real_distribution<float> ddist(0.0f, 3.1415f * 2.0f);
	std::uniform_real_distribution<float> odist(0.0f, 3.1415f * 0.3f);
	std::uniform_real_distribution<float> rdist(6.0f, 20.0f);
	for (auto i = 0; i < 80; i++)
	{
		boxes.push_back(std::make_unique<Box>(
			wnd.Gfx(), rng, adist,
			ddist, odist, rdist
			)
		);
	}
	wnd.Gfx().SetProjection(DirectX::XMMatrixPerspectiveFovLH(1.0f,3.0f/4.0f,0.5f,40.0f));
}

int App::Go() {
	while (true)
	{
		if (const auto ecode = Window::ProcessMessage()) {
			return *ecode;
		}
		DoFrame();
	}
}

App::~App()
{
}

void App::DoFrame() {
	//const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	//wnd.Gfx().ClearBuffer(c,c,1.0f);
	//wnd.Gfx().DrawTestTriangle(timer.Peek());
	//wnd.Gfx().EndFrame();
	auto dt = timer.Mark();
	wnd.Gfx().ClearBuffer(0.07f, 0.0f, 0.12f);
	for (auto& b:boxes)
	{
		b->Update(dt);
		b->Draw(wnd.Gfx());
	}
	wnd.Gfx().EndFrame();
}