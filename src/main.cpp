#include "cellState.hpp"
#include "windowLength.hpp"
#include <iostream>
#include <array>
#include <vector>
/*
-Estado: vivo/muerto - *bool
-Posición: (3,5) - *vector *array
*/

struct Cell{
  bool status;
  std::array<int,2> coor;
  int id;
  //int coor_x;
  //int coor_y;
};

void PrintStatus(bool cell_status){

  CellState cell_state;
  if(cell_status == 1){
    std::cout << cell_state.alive << "\n";
  }else{
    std::cout << cell_state.dead  << "\n";
  }
}

int main(){
  int side_grid = 5;
  //int size_grid = side_grid * side_grid;

  std::vector<std::vector<Cell>> cell_grid (side_grid);
  int contador_id = 1;
  for(int i{0}; i<side_grid; ++i){
    cell_grid[i].resize(side_grid);

    for(int j{0}; j<side_grid; ++j){
      Cell cell;
      cell.status = true;
      //cell.coor = [i],[j];
      cell.coor[0] = i;
      cell.coor[1] = j;
      cell.id = contador_id;
      cell_grid[i][j] = cell;
      ++contador_id;
    }
  }
  //std::vector<Cell> cell_grid (size_grid);

  
  for(size_t i{0}; i<cell_grid.size(); ++i){
    for(size_t j{0}; j<cell_grid[i].size(); ++j){
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << " ";
      //PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }
  /*
  CellState cell;
  std::cout << cell.alive << cell.dead << cell.alive << "\n";
  */

	std::cout << "Oh la la\n";
  std::cout << "window length: " << utils::GetWindowLength() << "\n";
	return 0;
}
