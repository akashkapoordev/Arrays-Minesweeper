#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Global;
		using namespace UI::UIElement;

		BoardView::BoardView(BoardController* controller)
		{
			board_controller = controller;
			createBackgroundImage();
			createBoardImage();
		}
		BoardView::~BoardView()
		{
			destroy();
		}

		void BoardView::initialize()
		{
			intializeBackgroundImage();
			intializeBoardImage();
		}

		void BoardView::update()
		{
			backround_image->update();
			board_image->update();
		}

		void BoardView::render()
		{
			backround_image->render();
			board_image->render();
		}

		void BoardView::createBackgroundImage()
		{
			backround_image = new ImageView();
		}

		void BoardView::intializeBackgroundImage()
		{
			sf::RenderWindow* window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			backround_image->initialize(Config::background_texture_path, window->getSize().x, window->getSize().y, sf::Vector2f(0, 0));
			backround_image->setImageAlpha(background_alpha);
		}

		void BoardView::createBoardImage()
		{
			board_image = new ImageView();
		}

		void BoardView::intializeBoardImage()
		{
			board_image->initialize(Config::board_texture_path, board_width, board_height, sf::Vector2f(0, 0));
			board_image->setCentreAlinged();
		}

		void BoardView::destroy()
		{
			delete(backround_image);
			delete(board_image);
		}

	}
}







