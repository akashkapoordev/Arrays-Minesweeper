#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using  namespace Main;
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
	int GameplayController::getMintCount()
	{
		return ServiceLocator::getInstance()->getBoardService()->getMinesCount();
	}
	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
		case Gameplay::GameResult::WIN:
			winGame();
			break;
		case Gameplay::GameResult::LOSE:
			loseGame();
			break;
		default:
			break;
		}
	}
	void GameplayController::beginGameOverTimer()
	{
		remaining_timer = game_over_time;
	}
	void GameplayController::winGame()
	{
	}
	void GameplayController::loseGame()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOSE;
			beginGameOverTimer();
			ServiceLocator::getInstance()->getBoardService()->showBoard();
			ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}
	void GameplayController::updateRemainingTimer()
	{
		remaining_timer -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
}