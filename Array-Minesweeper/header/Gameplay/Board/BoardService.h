#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardService
		{
		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			void resetBoard();
			int getMinesCount();
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType buttonType);
			void showBoard();
			BoardState getBoardState();
			void setBoardState(BoardState state);

		private:
			BoardController* board_controller;
		};
	}

}