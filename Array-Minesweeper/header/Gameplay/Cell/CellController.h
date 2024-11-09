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
			CellController(int cell_index);
			~CellController();

			void initialize(float cell_width, float cell_height);
			void update();
			void render();

			CellState getCellState();
			void setCellState(CellState state);

			CellValue getCellValue();
			void setCellValue(CellValue value);

			void resetCell();

			int getCellIndex();

		private:
			CellView* cell_view;
			CellModel* cell_model;
		};

	}
}