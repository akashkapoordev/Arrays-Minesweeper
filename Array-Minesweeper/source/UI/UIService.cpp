#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace GameplayUI;
	using namespace UIElement;
	using namespace Interface;
<<<<<<< Updated upstream
	using namespace Instructions;
	using namespace Credits;

	UIService::UIService()
	{
		splash_screen_ui_controller = nullptr;
		main_menu_ui_controller = nullptr;
		instructions_screen_ui_controller = nullptr;
		gameplay_ui_controller = nullptr;
		credit_screen_ui_controller = nullptr;
=======
	using namespace GameplayUI;
	using namespace CustomGrid;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;
		credit_screen_controller = nullptr;
		instructions_screen_controller = nullptr;
		gameplay_controller = nullptr;
		custom_grid_controller = nullptr;
>>>>>>> Stashed changes

		createControllers();
	}

	void UIService::createControllers()
	{
<<<<<<< Updated upstream
		splash_screen_ui_controller = new SplashScreenUIController();
		main_menu_ui_controller = new MainMenuUIController();
		instructions_screen_ui_controller = new InstructionsScreenUIController();
		gameplay_ui_controller = new GameplayUIController();
		credit_screen_ui_controller = new CreditsScreenUIController();
=======
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
		credit_screen_controller = new CreditsScreenUIController();
		instructions_screen_controller = new InstructionsScreenUIController();
		gameplay_controller = new GameplayUIController();
		custom_grid_controller = new CustomGridController();
>>>>>>> Stashed changes
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	void UIService::initializeControllers()
	{
<<<<<<< Updated upstream
		splash_screen_ui_controller->initialize();
		main_menu_ui_controller->initialize();
		instructions_screen_ui_controller->initialize();
		gameplay_ui_controller->initialize();
		credit_screen_ui_controller->initialize();
=======
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		credit_screen_controller->initialize();
		instructions_screen_controller->initialize();
		gameplay_controller->initialize();
		custom_grid_controller->initialize();
>>>>>>> Stashed changes
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_ui_controller;

		case GameState::INSTRUCTIONS:
			return instructions_screen_ui_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::CREDITS:
<<<<<<< Updated upstream
			return credit_screen_ui_controller;
=======
			return credit_screen_controller;
			break;
		case GameState::CUSTOMGRID :
			return custom_grid_controller;
			break;
		case GameState::GAMEPLAY:
			return gameplay_controller;
			break;
>>>>>>> Stashed changes

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
<<<<<<< Updated upstream
		delete(splash_screen_ui_controller);
		delete(main_menu_ui_controller);
		delete(instructions_screen_ui_controller);
		delete(gameplay_ui_controller);
		delete(credit_screen_ui_controller);
=======
		delete(splash_screen_controller);
		delete(main_menu_controller);
		delete(instructions_screen_controller);
		delete(credit_screen_controller);
		delete(gameplay_controller);
		delete(custom_grid_controller);
>>>>>>> Stashed changes
	}
}