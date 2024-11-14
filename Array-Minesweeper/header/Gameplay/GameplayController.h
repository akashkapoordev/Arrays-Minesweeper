#pragma once
namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WIN,
		LOSE
	};
	class GameplayController
	{
	public:

		float max_timer = 100.f;
		float remaining_timer;
		const float game_over_time = 11.f;
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void reset();
		float getRemainingTimer();
		int getMintCount();

		void endGame(GameResult result);
		void beginGameOverTimer();
		void showCredits();
	private:
		GameResult game_result;
		void winGame();
		void loseGame();
		void updateRemainingTimer();
	
	};


}