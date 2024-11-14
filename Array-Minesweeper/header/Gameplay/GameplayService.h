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
		float getMintCount();
		void endGame(GameResult result);

	private:
		GameplayController* gameplay_controller;
	};


}