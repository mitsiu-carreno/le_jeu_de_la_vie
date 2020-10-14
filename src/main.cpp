#include "cell.hpp"
#include "grid.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include <iostream>
#include <vector>

int main(){
  /////////------
  std::vector<std::vector<cell::Cell>> cell_grid = Grid::Initialize_Grid (); 
  //std::vector<cell::Cell> cell_grid (size_grid);

  //Grid::PrintGridDebug(cell_grid); 
  Grid::CalcNextStatus(cell_grid);

  //std::cout << "window length: " << utils::GetWindowLength() << "\n";

  // utils::ClearScreen();
  Grid::CheckCellStatus(cell_grid);   // Mariana

  Grid::PrintGrid(cell_grid);

  //DefineInitialStatus(cell_grid.size(), cell_grid);

 
	return 0;
  
}
