#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
		public:
			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;
			int flagged_count;


			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();

			void reset();
			int getMinesCount();

			void openCell(sf::Vector2i position);
			void processCellInput(Cell::CellController* cell_controller,UI::UIElement::ButtonType buttonType);
			void flagCell(sf::Vector2i position);

		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];

			void createBoard();
			void deleteBoard();
			void destroy();
		};
	}
}