#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController():random_engine(random_device())
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

		void BoardController::resetBoard()
		{
	
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					board[i][j]->resetCell();
				}
			}
		}
		void BoardController::reset()
		{
			resetBoard();
			flagged_count = 0;
			board_state = BoardState::FIRST_CELL;
		}
		int BoardController::getMinesCount()
		{
			return mines_count - flagged_count;
		}
		void BoardController::openCell(sf::Vector2i position)
		{
			if (board[position.x][position.y]->isCellOpen())
			{
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(position);
					board_state = BoardState::PLAYING;
				}
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
		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
		}
		void BoardController::populateMines(sf::Vector2i position)
		{
			std::uniform_int_distribution<int> x_distribution(0,number_of_columns - 1);
			std::uniform_int_distribution<int> y_distribution2(0, number_of_rows - 1);

			for (int i = 0; i < mines_count; i++)
			{
				int a = static_cast<int>(x_distribution(random_engine));
				int b = static_cast<int>(y_distribution2(random_engine));

				if (board[a][b]->getCellValue() == CellValue::MINE || (position.x == a && position.y == b))
				{
					i--;
				}
				else
				{
					board[a][b]->setCellValue(CellValue::MINE);
				}

			}
		}
		int BoardController::countMinesAround(sf::Vector2i position)
		{
			int mine_count = 0;
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if ((i == 0 && j == 0) || (!isValidCellPosition(sf::Vector2i(position.x + i, position.y + j)))) continue;

					if (board[i + position.x][j + position.y]->getCellValue() == CellValue::MINE)
					{
						mine_count++;
					}
				}
				return mines_count;
			}
		}
		bool BoardController::isValidCellPosition(sf::Vector2i position)
		{
			return position.x >= 0 && position.y >= 0 && position.x < number_of_columns && position.y < number_of_rows;
		}
		void BoardController::populateBoard(sf::Vector2i postion)
		{
			populateMines(sf::Vector2i(postion));
			populateCells();
		}
		void BoardController::populateCells()
		{
			for (int i = 0; i < number_of_rows; i++)
			{
				for (int j = 0; j < number_of_columns; j++)
				{
					if (board[i][j]->getCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(i, j)));
						board[i][j]->setCellValue(value);
					}
				}
			}
		}
	}
		
}