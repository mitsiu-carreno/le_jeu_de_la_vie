#ifndef GRID_H 
#define GRID_H
#include<vector>
// Forward declarations
void CreateGrid();
void PrintGrid(std::vector<std::vector<cell::Cell>> grid );
std::array<int,2> GetGridSize ( );
void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid );

#endif

