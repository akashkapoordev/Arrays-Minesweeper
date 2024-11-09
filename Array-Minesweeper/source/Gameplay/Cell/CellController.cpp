#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController(int cell_index)
		{
			cell_model = new CellModel(cell_index);
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
		int CellController::getCellIndex()
		{
			return cell_model->getCellIndex();
		}
	}

}