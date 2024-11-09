#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->initialize(getCellWidth(), getCellHeight());

			}
		}

		void BoardController::update()
		{
			board_view->update();
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->update();

			}
		}

		void BoardController::render()
		{
			board_view->render();
			for(int i = 0; i < number_of_columns; i++)
			{
				cells[i]->render();

			}
		}

		float BoardController::getCellWidth()
		{
			return board_view->getCellWidth();
		}

		float BoardController::getCellHeight()
		{
			return board_view->getCellHeight();
		}

		void BoardController::createBoard()
		{
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i] = new CellController(i);
			}
		}

		void BoardController::deleteBoard()
		{
			for (int i = 0; i < number_of_columns; i++)
			{
				delete(cells[i]);
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}

		void BoardController::reset()
		{
			for (int i = 0; i < number_of_columns; i++)
			{
				cells[i]->resetCell();
			}
		}
	}
}