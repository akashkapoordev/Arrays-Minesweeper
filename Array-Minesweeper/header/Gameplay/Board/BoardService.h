#pragma once
#include "../../header/Gameplay/Board/BoardController.h"
namespace Gameplay
{
	namespace Board
	{
		class BoardService
		{
		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			void resetBoard();

		private:
			BoardController* board_controller;
		};
	}

}