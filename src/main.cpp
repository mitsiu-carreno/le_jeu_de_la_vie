#include "cell.hpp"
#include "grid.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include <vector>

int main(){
  // Create grid based on window size and populate
	std::vector<std::vector<cell::Cell>> cell_grid = Grid::Initialize_Grid ();

  int gen_num {1};
  int alives;
	do{
    
    alives = Grid::GetCurrenAlive(cell_grid);
		Grid::PrintGrid(cell_grid);
    Grid::PrintInfo(gen_num, alives);

		Grid::CalcNextStatus(cell_grid);
    ++gen_num;
		utils::Sleep(300);

    utils::ClearScreen();

  } while (alives > 0);

	return 0;
}
