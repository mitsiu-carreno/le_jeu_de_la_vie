#include "cell.hpp"
#include "grid.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(){

	int start {1};

	std::vector<std::vector<cell::Cell>> cell_grid = Grid::Initialize_Grid ();


	do{

		Grid::PrintGrid(cell_grid);

		Grid::CalcNextStatus(cell_grid);

    utils::ClearScreen();

  } while (start==1) ;

	return 0;
}
