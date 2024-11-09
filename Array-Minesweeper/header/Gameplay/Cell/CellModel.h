#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
namespace Gameplay
{
	namespace Cell
	{
		enum class CellState
		{
			HIDDEN,
			OPEN,
			FLAGGED,
		};

		enum class CellValue
		{
			EMPTY,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			MINE,
		};

		class CellModel
		{
		public:

			sf::Vector2i cell_position;

			CellModel(sf::Vector2i position);
			~CellModel();

			void initialize();
			void update();
			void render();


			CellState getCellState();
			void setCellState(CellState state);

			CellValue getCellValue();
			void setCellValue(CellValue value);

			void reset();

			sf::Vector2i getCellIndex();

		private:
			CellState cell_state;
			CellValue cell_value;
		};
	}
}