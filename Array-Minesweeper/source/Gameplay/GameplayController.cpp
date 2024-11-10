#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayController::GameplayController()
	{
	}

	GameplayController::~GameplayController()
	{
	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{
		updateRemainingTimer();

	}

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		remaining_timer = max_timer;
		ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}
	float GameplayController::getRemainingTimer()
	{
		return remaining_timer;
	}
	void GameplayController::updateRemainingTimer()
	{
		remaining_timer -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
}