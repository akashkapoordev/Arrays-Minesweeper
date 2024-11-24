#pragma once
#include "../../header/UI/UIElement/ImageView.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardView
		{
		public:

			const float background_alpha = 85.f;
			const float board_width = 866.f;
			const float board_height = 1080.f;
			const float board_width_offset = 115.f;
			const float board_height_offset = 329.f;

			BoardView(BoardController* controller);
			~BoardView();

			void initialize();
			void update();
			void render();

			float getCellWidth();
			float getCellHeight();


		private:
			BoardController* board_controller;
			UI::UIElement::ImageView* backround_image;
			UI::UIElement::ImageView* board_image;

			void createBackgroundImage();
			void intializeBackgroundImage();

			void createBoardImage();
			void intializeBoardImage();

			void destroy();
		};

	}

}