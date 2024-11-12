#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Sound/SoundService.h"
#include <iostream>


namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Sound;

		CellView::CellView(CellController* controller)
		{
			m_controller = controller;
			createButtonView();
		}

		CellView::~CellView()
		{
			destroyButtonView();
		}

		void CellView::initialize(float width,float height)
		{
			intializeButtonView(width,height);
			registerButtonCallback();

		}

		void CellView::update()
		{
			updateButtonView();
		}

		void CellView::render()
		{
			renderButtonView();
		}

		sf::Vector2f CellView::getCellScreenPosition(float width,float height)
		{
			sf::Vector2i cell_index = m_controller->getCellIndex();

			float x_position = cell_left_offset + (cell_index.y * width);
			float y_position = cell_top_offset + cell_index.x * height;
			return sf::Vector2f(x_position,y_position);
		}

		void CellView::createButtonView()
		{
			cell_view = new ButtonView();
		}

		void CellView::intializeButtonView(float width,float height)
		{
			cell_view->initialize("Cell",Config::cells_texture_path, width * slice_count, height, getCellScreenPosition(width,height));
		}

		void CellView::updateButtonView()
		{
			cell_view->update();
		}

		void CellView::renderButtonView()
		{
			setCellTetxure();
			cell_view->render();
		}

		void CellView::destroyButtonView()
		{
			delete(cell_view);
		}
		void CellView::setCellTetxure()
		{
			int index = static_cast<int>(m_controller->getCellValue());

			switch (m_controller->getCellState())
			{
			case Gameplay::Cell::CellState::HIDDEN:
				cell_view->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;
			case Gameplay::Cell::CellState::OPEN:
				cell_view->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
				break;
			case Gameplay::Cell::CellState::FLAGGED:
				std::cout << "flagged" << std::endl;
				cell_view->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
				break;
			default:
				break;
			}
		}
		void CellView::registerButtonCallback()
		{
			cell_view->registerCallbackFuntion(std::bind(&CellView::cellButtonCallback, this, std::placeholders::_1));
		}
		void CellView::cellButtonCallback(ButtonType button)
		{
			ServiceLocator::getInstance()->getBoardService()->processCellInput(m_controller, button);
		}
	}

}
