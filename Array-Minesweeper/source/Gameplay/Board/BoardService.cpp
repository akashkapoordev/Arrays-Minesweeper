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
		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}
		void BoardService::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType buttonType)
		{
			board_controller->processCellInput(cell_controller, buttonType);
		}
		void BoardService::showBoard()
		{
			board_controller->showBoard();
		}
		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}
		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}
	}

}