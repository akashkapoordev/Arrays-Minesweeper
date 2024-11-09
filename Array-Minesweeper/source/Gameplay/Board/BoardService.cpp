#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	namespace Board
	{
		BoardService::BoardService()
		{
			board_controller = new BoardController();
		}

		BoardService::~BoardService()
		{
			delete(board_controller);
		}

		void BoardService::initialize()
		{
			board_controller->initialize();

		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}
	}

}