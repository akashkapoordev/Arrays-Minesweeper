#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include <sstream>
#include <iomanip>

namespace UI
{
	namespace Gameplay
	{
		using namespace UI::UIElement;
		using namespace Global;

		GameplayUIController::GameplayUIController()
		{
			createTextViews();
		}

		GameplayUIController::~GameplayUIController()
		{
			delete(time_text);
		}

		void GameplayUIController::initialize()
		{
			// Initialize all the UI elements
			initializeTextViews();
		}

		void GameplayUIController::update()
		{
			// Update all the UI elements
			updateTimeText();
		}

		void GameplayUIController::render()
		{
			// Render all the UI elements
			time_text->render();
		}

		void GameplayUIController::show()
		{
			// Show all the UI elements
			time_text->show();
		}

		void GameplayUIController::createTextViews()
		{
			time_text = new TextView();
		}

		void GameplayUIController::createButtons()
		{

		}

		void GameplayUIController::initializeTextViews()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset),FontType::DS_DIGIB,font_size,text_color);
		}

		void GameplayUIController::initializeButtons()
		{
		}

		void GameplayUIController::updateTimeText()
		{
			int remaining_time = ServiceLocator::getInstance()->getGameplayService()->getRemainingTimer();
			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << remaining_time;
			std::string string_remaining_time = stream.str();

			time_text->setText(string_remaining_time);
			time_text->update();
		}

	}
}