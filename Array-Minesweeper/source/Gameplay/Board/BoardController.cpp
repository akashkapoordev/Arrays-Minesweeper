#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			cell_controller = new CellController();
		}

		BoardController::~BoardController()
		{
			delete(board_view);
			delete(cell_controller);
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			cell_controller->initialize();
		}

		void BoardController::update()
		{
			board_view->update();
			cell_controller->update();
		}

		void BoardController::render()
		{
			board_view->render();
			cell_controller->render();
		}

		void BoardController::createBoard()
		{
		}

		void BoardController::deleteBoard()
		{
		}

		void BoardController::destroy()
		{
		}

		void BoardController::reset()
		{
		}
	}
}