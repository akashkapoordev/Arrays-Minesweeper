#pragma once
#include "../../header/Gameplay/GameplayController.h"
namespace Gameplay
{
	class GameplayService
	{
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();


		void startGame();
		float getRemainingTimer();

	private:
		GameplayController* gameplay_controller;
	};


}