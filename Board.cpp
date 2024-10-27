#include "Board.h"
#include <assert.h>
//#include <iostream>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	//std::cout << "loc.x: " << loc.x << ", loc.y: " << loc.y << std::endl;
	/*assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);*/
	gfx.DrawRectDim(loc.x * dimention, loc.y * dimention, dimention, dimention,c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc)
{
	return loc.x >=0&&loc.x<width&&loc.y>=0&&loc.y<height;
}
