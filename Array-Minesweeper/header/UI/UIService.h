#pragma once
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/Instructions/InstructionsScreenUIController.h"
#include "../../header/UI/Credits/CreditsScreenUIController.h"
#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/CustomUIGrid/CustomGridController.h"

namespace UI
{
	class UIService
	{
	private:
<<<<<<< Updated upstream
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;
		MainMenu::MainMenuUIController* main_menu_ui_controller;
		Instructions::InstructionsScreenUIController* instructions_screen_ui_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		Credits::CreditsScreenUIController* credit_screen_ui_controller;
=======
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;
		Credits::CreditsScreenUIController* credit_screen_controller;
		Instructions::InstructionsScreenUIController* instructions_screen_controller;
		GameplayUI::GameplayUIController* gameplay_controller;
		CustomGrid::CustomGridController* custom_grid_controller;
>>>>>>> Stashed changes

		void createControllers();
		void initializeControllers();
		Interface::IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}