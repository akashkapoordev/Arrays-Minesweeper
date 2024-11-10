#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include "../../header/UI/UIElement/ButtonView.h"
namespace UI
{
	namespace Gameplay
	{
		class GameplayUIController:public Interface::IUIController
		{
		public:

			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			UI::UIElement::TextView* time_text;
			UI::UIElement::TextView* flag_counter_text;
			UI::UIElement::TextView* game_over_text;
			UI::UIElement::ButtonView* reset_button;

			void createTextViews();
			void createButtons();
			void initializeTextViews();
			void initializeButtons();
			void updateTimeText();

		};
	}
}