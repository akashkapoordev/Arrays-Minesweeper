#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include <sstream>
#include <iomanip>
#include <iostream>

namespace UI
{
	namespace GameplayUI
	{
		using namespace UI::UIElement;
		using namespace Global;

		GameplayUIController::GameplayUIController()
		{
			createTextViews();
			createButtons();
		}

		GameplayUIController::~GameplayUIController()
		{
			delete(time_text);
			delete(mint_text);
			delete(reset_button);
		}

		void GameplayUIController::initialize()
		{
			// Initialize all the UI elements
			initializeTextViews();
			initializeButtons();
		}

		void GameplayUIController::update()
		{
			// Update all the UI elements
			reset_button->update();
			updateTimeText();
			updateMineText();

		}

		void GameplayUIController::render()
		{
			// Render all the UI elements
			reset_button->render();
			time_text->render();
			mint_text->render();
		}

		void GameplayUIController::show()
		{
			// Show all the UI elements
			reset_button->show();
			time_text->show();
			mint_text->show();
		}

		void GameplayUIController::createTextViews()
		{
			time_text = new TextView();
			mint_text = new TextView();
		}

		void GameplayUIController::createButtons()
		{
			reset_button = new ButtonView();

		}

		void GameplayUIController::initializeTextViews()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset),FontType::BUBBLE_BOBBLE,font_size,text_color);
			mint_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset), FontType::BUBBLE_BOBBLE, font_size, text_color);
		}

		void GameplayUIController::initializeButtons()
		{
			reset_button->initialize("Reset", Config::restart_button_texture_path, button_width, button_height, sf::Vector2f(restart_button_left_offset, restart_button_top_offset));
			registerButtonCallback();
		}

		void GameplayUIController::updateTimeText()
		{
			int remaining_time = ServiceLocator::getInstance()->getGameplayService()->getRemainingTimer();
			std::cout << remaining_time << std::endl;
			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << remaining_time;
			std::string string_remaining_time = stream.str();

			time_text->setText(string_remaining_time);
			time_text->update();
		}

		void GameplayUIController::updateMineText()
		{
			int remaining_mine = static_cast<int>( ServiceLocator::getInstance()->getGameplayService()->getMintCount());
			

			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << remaining_mine;
			std::string string_remaining_mine = stream.str();
			std::cout << string_remaining_mine << std::endl;
			mint_text->setText(string_remaining_mine);
			mint_text->update();

		
		}

		void GameplayUIController::resetButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGameplayService()->startGame();
		}

		void GameplayUIController::registerButtonCallback()
		{
			reset_button->registerCallbackFuntion(std::bind(&GameplayUIController::resetButtonCallback, this));
		}

	}
}