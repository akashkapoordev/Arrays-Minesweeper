#pragma once
#include "../../Gameplay/Cell/CellController.h"
#include "../../UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellView
		{
		public:

			const int tile_size = 32;

			CellView(CellController* controller);
			~CellView();

			void initialize();
			void update();
			void render();

		private:
			CellController* m_controller;
			UI::UIElement::ButtonView* m_button_view;

			void createButtonView();
			void intializeButtonView(float width,float height);
			void updateButtonView();
			void renderButtonView();
			void destroyButtonView();
		};

	}
}