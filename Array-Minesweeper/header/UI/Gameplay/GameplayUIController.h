#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/UI/UIElement/ButtonView.h"
namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController:public Interface::IUIController
		{
		public:

			const int font_size = 110;

			const float mine_text_top_offset = 65.f;
			const float mine_text_left_offset = 660.f;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			const float restart_button_top_offset = 100.f;
			const float restart_button_left_offset = 920.f;

			const float button_height = 80.f;
			const float button_width = 80.f;

			const int tile_height = 32;

			const sf::Color text_color = sf::Color::Red;


			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			UI::UIElement::TextView* time_text;
			UI::UIElement::TextView* mint_text;
			UI::UIElement::TextView* game_over_text;
			UI::UIElement::ButtonView* reset_button;

			void createTextViews();
			void createButtons();
			void initializeTextViews();
			void initializeButtons();
			void updateTimeText();
			void updateMineText();

			void resetButtonCallback();
			void registerButtonCallback();
	

		};
	}
}