#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/Cell/CellModel.h"


namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;
		using namespace Global;

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
			float x_position = cell_left_offset + (m_controller->getCellIndex() * width);
			float y_position = height;
			return sf::Vector2f(x_position,y_position);
		}

		void CellView::createButtonView()
		{
			m_button_view = new ButtonView();
		}

		void CellView::intializeButtonView(float width,float height)
		{
			m_button_view->initialize("Cell",Config::cells_texture_path, width * slice_count, height, getCellScreenPosition(width,height));
		}

		void CellView::updateButtonView()
		{
			m_button_view->update();
		}

		void CellView::renderButtonView()
		{
			setCellTetxure();
			m_button_view->render();
		}

		void CellView::destroyButtonView()
		{
			delete(m_button_view);
		}
		void CellView::setCellTetxure()
		{
			int index = static_cast<int>(m_controller->getCellValue());

			switch (m_controller->getCellState())
			{
			case Gameplay::Cell::CellState::HIDDEN:
				m_button_view->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;
			case Gameplay::Cell::CellState::OPEN:
				m_button_view->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
				break;
			case Gameplay::Cell::CellState::FLAGGED:
				m_button_view->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
				break;
			default:
				break;
			}
		}
	}

}
