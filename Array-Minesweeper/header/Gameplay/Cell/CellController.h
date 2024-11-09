#pragma once
namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellController
		{
		public:
			CellController();
			~CellController();

			void initialize();
			void update();
			void render();

		private:
			CellView* cell_view;
		};

	}
}