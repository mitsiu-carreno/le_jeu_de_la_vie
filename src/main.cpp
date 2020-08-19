#include "cellState.hpp"
#include "windowLength.hpp"
#include <iostream>
#include <array>
/*
-Estado: vivo/muerto - *bool
-Posición: (3,5) - *vector *array
*/

struct Cell{
  bool status;
  std::array<int,2> coor;
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
  int size_grid = side_grid * side_grid;

  std::vector<std::vector<Cell>> cell_grid (side_grid);
  for(size_t i{0}; i<side_grid; ++i){
    cell_grid[i].resize(side_grid);
    
    for(size_t j{0}; j<side_grid; ++j){
      cell.status = true;
      cell.coor = [i],[j];
    }
  }
  //std::vector<Cell> cell_grid (size_grid);
  // b
  
  // a


  Cell celula;
  celula.status = true;
  celula.coor[0] = 6;
  celula.coor[1] = 3;


  Cell celula2;
  celula2.status = false;
  celula2.coor[0] = 5;
  celula2.coor[1] = 3;

  PrintStatus(celula.status);
  PrintStatus(celula2.status);
  /*
  CellState cell;
  std::cout << cell.alive << cell.dead << cell.alive << "\n";
  */

	std::cout << "Oh la la\n";
  utils::GetWindowLength();
	return 0;
}
