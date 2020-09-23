#ifndef GRID_H 
#define GRID_H
#include<vector>
// Forward declarations
void CreateGrid();
void PrintGridDebug(std::vector<std::vector<cell::Cell>> cell_grid);
void PrintGrid(std::vector<std::vector<cell::Cell>> grid );
std::array<int,2> GetGridSize ( );
void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid );

#endif

