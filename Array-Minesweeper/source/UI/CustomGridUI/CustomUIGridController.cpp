#include "../../header/UI/CustomUIGrid/CustomGridController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"


namespace UI
{
	namespace CustomGrid
	{
		using namespace UI::UIElement;
		using namespace Global;

		CustomGridController::CustomGridController()
		{
			createGridBackgroundImage();
			createButton();
			createTexBox();
		}
		CustomGridController::~CustomGridController()
		{
			delete(custom_grid_background);
			delete(start_button);
			delete(text_box);
		}
		void CustomGridController::initialize()
		{
			initializeGridBackgroundImage();
			intializeButton();
			initializeTextBox();
		}
		void CustomGridController::update()
		{
			custom_grid_background->update();
			start_button->update();
			text_box->update();
		}
		void CustomGridController::render()
		{
			custom_grid_background->render();
			start_button->render();
			text_box->render();
			
		}
		void CustomGridController::show()
		{
			custom_grid_background->show();
			start_button->show();
		}
		void CustomGridController::createGridBackgroundImage()
		{
			custom_grid_background = new ImageView();
		}
		void CustomGridController::createButton()
		{
			start_button = new ButtonView();
		}
		void CustomGridController::createTexBox()
		{
			text_box = new TextBox();
    
		}
		void CustomGridController::initializeGridBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			custom_grid_background->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		}
		void CustomGridController::intializeButton()
		{
			start_button->initialize("Start Game", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
			start_button->setCentreAlinged();
		}
		void CustomGridController::initializeTextBox()
		{
			text_box->initialize(600, 50, sf::Vector2f(0, 400), sf::Color(200, 200, 200), sf::Color::Black, 2);
			text_box->setBoxAlignCenter();
		}
	}
}