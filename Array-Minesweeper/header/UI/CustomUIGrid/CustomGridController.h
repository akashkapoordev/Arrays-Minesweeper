#pragma once
#include "../../UI/UIElement/ImageView.h"
#include "../../UI/UIElement/ButtonView.h"
#include "../../UI/Interface/IUIController.h"
#include "../../UI/UIElement/TextBox.h"
namespace UI
{
	namespace CustomGrid
	{
		class CustomGridController:public Interface::IUIController
		{
		public:
			CustomGridController();
			~CustomGridController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float play_button_y_position = 800.f;

			UI::UIElement::ImageView* custom_grid_background;
			UI::UIElement::ButtonView* start_button;
			UI::UIElement::TextBox* text_box;


			void createGridBackgroundImage();
			void createButton();
			void createTexBox();
			void initializeGridBackgroundImage();
			void intializeButton();
			void initializeTextBox();

		};
	}
}