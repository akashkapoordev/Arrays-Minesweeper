#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellModel.h"

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
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j]->initialize(cell_width, cell_height);
				}

			}
		}

		void BoardController::update()
		{
			board_view->update();
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j]->update();
				}

			}
		}

		void BoardController::render()
		{
			board_view->render();
			for(int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j]->render();
				}

			}
		}

		void BoardController::createBoard()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j] = new CellController(sf::Vector2i(i, j));
				}
			}
		}

		void BoardController::deleteBoard()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					delete(board[i][j]);
				}
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}

		void BoardController::reset()
		{
			flagged_count = 0;
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j]->resetCell();
				}
			}
		}
		int BoardController::getMinesCount()
		{
			return mines_count - flagged_count;
		}
		void BoardController::openCell(sf::Vector2i position)
		{
			if (board[position.x][position.y]->isCellOpen())
			{
				board[position.x][position.y]->openCell();
			}
		}
		void BoardController::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType buttonType)
		{
			switch (buttonType)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellIndex());
				break;
			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellIndex());
				break;
			default:
				break;
			}
		}
		void BoardController::flagCell(sf::Vector2i position)
		{
			switch (board[position.x][position.y]->getCellState())
			{
			case Cell::CellState::FLAGGED:
				flagged_count++;
				break;
			case Cell::CellState::HIDDEN:
				flagged_count--;
				break;
			default:
				break;
			}

			board[position.x][position.y]->flagCell();
		}
	}
}