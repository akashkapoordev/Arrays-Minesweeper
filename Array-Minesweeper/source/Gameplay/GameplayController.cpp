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
		if(TimerIsOver())
			endGame(GameResult::LOSE);
	}

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		game_result = GameResult::NONE;
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
		}
	}
	void GameplayController::beginGameOverTimer()
	{
		remaining_timer = game_over_time;
	}
	void GameplayController::winGame()
	{
		game_result = GameResult::WIN;
		ServiceLocator::getInstance()->getBoardService()->flagAllMines();
		ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
		
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
		if (game_result == GameResult::WIN)
			return;
		remaining_timer -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void GameplayController::showCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
	bool GameplayController::TimerIsOver()
	{
		return remaining_timer<=1;
	}
}