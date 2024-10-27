#pragma once
#include "Board.h"

class Snake
{
private:

	class Segment {
	private:
		Location loc;
		Color c;
	public:
		void InitHead(const Location& in_loc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	};
private:

	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int snakespeed = 100;

public: 
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
};

