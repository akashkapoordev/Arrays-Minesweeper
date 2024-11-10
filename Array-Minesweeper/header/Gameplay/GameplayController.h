#pragma once
namespace Gameplay
{
	class GameplayController
	{
	public:

		float max_timer;
		float remaining_timer;
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void reset();
		float getRemainingTimer();
		int getMintCount();


	private:
		void updateRemainingTimer();
	};


}