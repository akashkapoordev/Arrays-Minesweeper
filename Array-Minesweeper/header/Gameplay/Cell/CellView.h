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

			const float cell_top_offset = 274.f;
			const float cell_left_offset = 583.f;
			const int tile_size = 32;
			int slice_count = 12;

			CellView(CellController* controller);
			~CellView();

			void initialize(float width,float height);
			void update();
			void render();

			sf::Vector2f getCellScreenPosition();

		private:
			CellController* m_controller;
			UI::UIElement::ButtonView* m_button_view;

			void createButtonView();
			void intializeButtonView(float width,float height);
			void updateButtonView();
			void renderButtonView();
			void destroyButtonView();

			void setCellTetxure();
		};

	}
}