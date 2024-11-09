#include "../../header/Gameplay/Cell/CellModel.h"
#include <iostream>

namespace Gameplay
{
	namespace Cell
	{

		CellModel::CellModel(sf::Vector2i position)
		{
			this->cell_position = position;
		}

		CellModel::~CellModel()
		{
		}

		void CellModel::initialize()
		{

		}

		void CellModel::update()
		{

		}

		void CellModel::render()
		{

		}

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		void CellModel::reset()
		{
			cell_state = CellState::HIDDEN;
			cell_value = CellValue::EMPTY;
		}
		sf::Vector2i CellModel::getCellIndex()
		{
			return cell_position;
		}
	}
}