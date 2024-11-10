#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/ServiceLocator.h"
#include <iostream>

namespace Gameplay
{
	namespace Cell
	{
		inline std::ostream& operator<<(std::ostream& os, const CellState& state)
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
		using namespace Global;
		CellController::CellController(sf::Vector2i position)
		{
			cell_model = new CellModel(position);
			cell_view = new CellView(this);

		}

		CellController::~CellController()
		{
			delete(cell_model);
			delete(cell_view);
		}

		void CellController::initialize(float cell_width,float cell_height)
		{

			cell_view->initialize(cell_width,cell_height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}
		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		void CellController::setCellState(CellState state)
		{
			cell_model->setCellState(state);
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}

		void CellController::setCellValue(CellValue value)
		{
			cell_model->setCellValue(value);
		}

		void CellController::resetCell()
		{
			cell_model->reset();
		}
		sf::Vector2i CellController::getCellIndex()
		{
			return cell_model->getCellIndex();
		}
		void CellController::openCell()
		{
			if (CellState::FLAGGED != cell_model->getCellState())
			{
				cell_model->setCellState(CellState::OPEN);
				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			}
		}
		void CellController::flagCell()
		{
			std::cout << cell_model->getCellState() << std::endl;

          
			switch (cell_model->getCellState())
			{
			case CellState::FLAGGED:
				cell_model->setCellState(CellState::HIDDEN);
				break;
			case CellState::HIDDEN:
				cell_model->setCellState(CellState::FLAGGED);
				break;

				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			}
		}
	}

}