#include "cell.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "initialState.hpp"
#include <iostream>
#include <vector>


//#include "initialState.hpp"

void PrintStatus(bool cell_status){
  if(cell_status == 1){
    std::cout << cell::states[cell::StateCatalog::alive] << "\n";
  }else{
    std::cout << cell::states[cell::StateCatalog::dead] << "\n";
  }
}


void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid){ 
//
//	for(std::vector v_ext : grid){
//
//		for(std::vector v_int : grid){
//		
//			std::cout << ;
//
//		}
//	}
}


int main(){

  int side_grid = 5;
  //int size_grid = side_grid * side_grid;

  std::vector<std::vector<cell::Cell>> cell_grid (side_grid);
  
  int contador_id = 1;
  
  for(int i{0}; i < side_grid; ++i){
    cell_grid[i].resize(side_grid);

    for(int j{0}; j < side_grid; ++j){
      cell::Cell cell;
      cell.status = true;
      cell.coor[0] = i;
      cell.coor[1] = j;
      cell.id = contador_id;
      cell_grid[i][j] = cell;
      ++contador_id;
    }
  }
  //std::vector<cell::Cell> cell_grid (size_grid);

  
  for(size_t i{0}; i<cell_grid.size(); ++i){
    for(size_t j{0}; j<cell_grid[i].size(); ++j){
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << "\n";
      //PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }


  //std::cout << "window length: " << utils::GetWindowLength() << "\n";
  
  utils::ClearScreen();

CheckCellStatus(cell_grid);

DefineInitialStatus(cell_grid.size(), cell_grid);

for(size_t i{0}; i<cell_grid.size(); ++i){
    for(size_t j{0}; j<cell_grid[i].size(); ++j){
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << "\n";
      PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }

	return 0;
}
