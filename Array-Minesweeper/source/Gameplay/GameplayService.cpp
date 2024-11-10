#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::startGame()
	{
		gameplay_controller->reset();
	}

	float GameplayService::getRemainingTimer()
	{
		return gameplay_controller->getRemainingTimer();
	}

	float GameplayService::getMintCount()
	{
		return gameplay_controller->getMintCount();
	}



}