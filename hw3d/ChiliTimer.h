#pragma once
#include <chrono>
#include <iomanip>

class ChiliTimer
{
public:
	ChiliTimer() noexcept;
	float Mark() noexcept;
	float Peek() const noexcept;
private:
	std::chrono::steady_clock::time_point last;
};