#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
	static constexpr int dimention = 20;
	static constexpr int width=25, height=25;
	Graphics& gfx;
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc);
};

