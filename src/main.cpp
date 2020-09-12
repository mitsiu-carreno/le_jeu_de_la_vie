#include "cell.hpp"
#include "grid.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include "initialState.hpp"
#include <iostream>
#include <vector>


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
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1];
      //PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }

  for (size_t i{ 0 }; i < cell_grid.size(); ++i) {
      for (size_t j{ 0 }; j < cell_grid.size(); ++j) {
          std::cout << cell_grid[i][j].id ;
          int temp{ static_cast<int>(cell_grid.size())};

          if (cell_grid [i][j].id == 1) {
              std::cout << "A ";
          }
          if (cell_grid [i][j].id > 1 && cell_grid [i][j].id < temp) {
              std::cout << "B ";
          }
          if (cell_grid [i][j].id == temp) {
              std::cout << "C ";
          }
          if (cell_grid [i][j].id == temp * temp - (temp - 1)) {
              std::cout << "D ";
          }
          if (cell_grid [i][j].id > temp* temp - (temp - 1) && cell_grid [i][j].id < temp * temp) {
              std::cout << "E ";
          }
          if (cell_grid [i][j].id == temp * temp) {
              std::cout << "F ";
          }
          if (i > 0 && i < cell_grid.size()-1 && j == 0) {
              std::cout << "G ";
          }
          if (i > 0 && i < cell_grid.size() - 1 && j == 4) {
              std::cout << "H ";
          }
          else {
              std::cout << "I ";
          }
      }
      std::cout << "\n";
  }


  //std::cout << "window length: " << utils::GetWindowLength() << "\n";
  
 // utils::ClearScreen();

CheckCellStatus(cell_grid);

PrintGrid(cell_grid);

DefineInitialStatus(cell_grid.size(), cell_grid);

for(size_t i{0}; i<cell_grid.size(); ++i){
    for(size_t j{0}; j<cell_grid[i].size(); ++j){
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << "\n";
      cell::PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }

	return 0;
}
