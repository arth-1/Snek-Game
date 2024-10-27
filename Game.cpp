
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng(std::random_device()()),
	snek({2,2}),
	goal(rng,brd,snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameIsOver) {
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			delta_loc = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			delta_loc = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			delta_loc = { -1,0 };
		}	
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			delta_loc = { 1,0 };
		}
		++snekMoveCounter;
		const Location next = snek.GetNextHeadLocation(delta_loc);

		if (snekMoveCounter >= snekMovePeriod) {
			snekMoveCounter = 0;
			if (!brd.IsInsideBoard(next)||
				snek.IsInTileExceptEnd(next)) {
				gameIsOver = true;
			}
			else {
				bool eating = next == goal.GetLocation();
				if (eating) {
					snek.Grow();
				}

				snek.MoveBy(delta_loc);
				if (eating) {
					goal.Respawn(rng, brd, snek);
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	snek.Draw(brd);
	goal.Draw(brd);
	if (gameIsOver) {
		SpriteCodex::DrawGameOver(200,200,gfx);
	}
}
