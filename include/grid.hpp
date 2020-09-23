#ifndef GRID_H 
#define GRID_H
#include<vector>
// Forward declarations

std::vector<std::vector<cell::Cell>> Initialize_Grid ();
std::array<int,2> GetGridSize( );
void PrintGrid(std::vector<std::vector<cell::Cell>> grid );
void DefineInitialStatus (int cell_gridsize, std::vector<std::vector<cell::Cell>> & cell_grid);



#endif

