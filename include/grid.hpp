#ifndef GRID_H 
#define GRID_H
#include<vector>
// Forward declarations
namespace Grid {
	void CreateGrid();
	void PrintGridDebug(std::vector<std::vector<cell::Cell>> &cell_grid);
	std::vector<std::vector<cell::Cell>> Initialize_Grid ();
	std::array<int,2> GetGridSize( );
	void PrintGrid(std::vector<std::vector<cell::Cell>> grid );
	void DefineInitialStatus (int cell_gridsize, std::vector<std::vector<cell::Cell>> &cell_grid);
	void CheckCellStatus(std::vector<std::vector<cell::Cell>> &grid );

  void CalcNextStatus(std::vector<std::vector<cell::Cell>> &grid);
  int GetNeighboursAlive(int cell_x, int cell_y, std::vector<std::vector<cell::Cell>> &grid);
}

#endif

