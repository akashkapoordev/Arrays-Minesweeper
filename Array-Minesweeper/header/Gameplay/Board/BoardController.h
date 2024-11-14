#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"
#include <random>
namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,
			PLAYING,
			COMPLETED
		};
		class BoardController
		{
		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;
			int flagged_count;
			std::default_random_engine random_engine;
			std::random_device random_device;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();

			void resetBoard();
			void reset();
			int getMinesCount();

			void openCell(sf::Vector2i position);
			void processCellInput(Cell::CellController* cell_controller,UI::UIElement::ButtonType buttonType);
			void flagCell(sf::Vector2i position);

			BoardState getBoardState();
			void setBoardState(BoardState state);

			void populateMines(sf::Vector2i position);
			int countMinesAround(sf::Vector2i position);
			bool isValidCellPosition(sf::Vector2i position);
			void populateBoard(sf::Vector2i postion);
			void populateCells();
			void openAllCells();
			void processCellValues(sf::Vector2i position);
			void openEmptyCells(sf::Vector2i position);
			void processEmptyCell(sf::Vector2i position);
			void processMineCell(sf::Vector2i position);
			void showBoard();
			void flagAllMines();
		

		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];
			BoardState board_state;

			void createBoard();
			void deleteBoard();
			void destroy();
		};
	}
}