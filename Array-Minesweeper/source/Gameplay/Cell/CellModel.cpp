#include "../../header/Gameplay/Cell/CellModel.h"
#include <iostream>

namespace Gameplay
{
	namespace Cell
	{
		std::ostream& operator<<(std::ostream& os, const CellState& state)
		{
			switch (state)
			{
			case CellState::HIDDEN:
				os << "HIDDEN";
				break;
			case CellState::OPEN:
				os << "OPEN";
				break;
			case CellState::FLAGGED:
				os << "FLAGGED";
				break;
			}
			return os;
		}

		CellModel::CellModel()
		{
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
			std::cout << "Cell State: " << cell_state << std::endl;
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
	}
}