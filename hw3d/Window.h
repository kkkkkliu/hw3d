#pragma once

#include <Windows.h>

class Window
{
private:
	class WindowClass {
	public:
		static const TCHAR* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static const TCHAR* wndClassName;
		static WindowClass wndClass;
		HINSTANCE hInst;
	};

public:
	Window(int width,int height,const TCHAR* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
	int width;
	int height;
	HWND hwnd;
};