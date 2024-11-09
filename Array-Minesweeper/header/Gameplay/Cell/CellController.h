#pragma once
namespace Gameplay
{
	namespace Cell
	{
		class CellModel;
		class CellView;
		enum class CellState;
		enum class CellValue;
		class CellController
		{
		public:
			CellController();
			~CellController();

			void initialize();
			void update();
			void render();

			CellState getCellState();
			void setCellState(CellState state);

			CellValue getCellValue();
			void setCellValue(CellValue value);

			void resetCell();

		private:
			CellView* cell_view;
			CellModel* cell_model;
		};

	}
}