#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"


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

		void CellView::initialize()
		{
			intializeButtonView(tile_size,tile_size);

		}

		void CellView::update()
		{
			updateButtonView();
		}

		void CellView::render()
		{
			renderButtonView();
		}

		void CellView::createButtonView()
		{
			m_button_view = new ButtonView();
		}

		void CellView::intializeButtonView(float width,float height)
		{
			m_button_view->initialize("Cell",Config::cells_texture_path, width, height, sf::Vector2f(0, 0));
		}

		void CellView::updateButtonView()
		{
			m_button_view->update();
		}

		void CellView::renderButtonView()
		{
			m_button_view->render();
		}

		void CellView::destroyButtonView()
		{
			delete(m_button_view);
		}
	}

}
