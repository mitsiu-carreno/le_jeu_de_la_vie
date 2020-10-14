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
          std::cout << "ID: "<< cell_grid[i][j].id <<" ";
          int size { static_cast<int>(cell_grid.size())};

          if (cell_grid [i][j].id == 1) { //esquina arriba-izquierda
              int temp;
              temp = cell_grid[i][j + 1].status + cell_grid[i+1][j + 1].status + cell_grid[i+1][j].status;
             
              std::cout << temp <<"  ";
          }
          else if (cell_grid [i][j].id > 1 && cell_grid [i][j].id < size) { // central arriba
              int temp;
              temp = cell_grid[i][j + 1].status + cell_grid[i + 1][j + 1].status + cell_grid[i + 1][j].status + cell_grid[i + 1][j-1].status + cell_grid[i][j - 1].status;

              std::cout << temp << "  ";;
          }
          else if (cell_grid [i][j].id == size) { // esquina arriba-derecha
              int temp;
              temp = cell_grid[i][j - 1].status + cell_grid[i + 1][j - 1].status + cell_grid[i + 1][j].status;

              std::cout << temp << "  ";
          }
          else if (cell_grid [i][j].id == size * size - (size - 1)) { // esquina abajo-izquierda
              int temp;
              temp = cell_grid[i-1][j].status + cell_grid[i - 1][j + 1].status + cell_grid[i][j+1].status;

              std::cout << temp << "  ";
          }
          else if (cell_grid [i][j].id > size* size - (size - 1) && cell_grid [i][j].id < size * size) {  // cental abajo
              int temp;
              temp = cell_grid[i][j-1].status + cell_grid[i-1][j-1].status + cell_grid[i-1][j].status + cell_grid[i-1][j+1].status + cell_grid[i][j+1].status;

              std::cout << temp << "  ";
          }
          else if (cell_grid [i][j].id == size * size) { // esquina abajo-derecha
              int temp;
              temp = cell_grid[i][j-1].status + cell_grid[i-1][j-1].status + cell_grid[i-1][j].status;

              std::cout << temp << "  ";
          }
          else if (i > 0 && i < cell_grid.size()-1 && j == 0) { //  lateral izquierda
              int temp;
              temp = cell_grid[i-1][j].status + cell_grid[i-1][j+1].status + cell_grid[i][j+1].status + cell_grid[i+1][j+1].status + cell_grid[i+1][j].status;

              std::cout << temp << "  ";
          }
          else if (i > 0 && i < cell_grid.size() - 1 && j == size-1) {  // lateral derecha 
              int temp;
              temp = cell_grid[i-1][j].status + cell_grid[i-1][j-1].status + cell_grid[i][j-1].status + cell_grid[i+1][j-1].status + cell_grid[i+1][j].status;

              std::cout << temp << "  ";
          }
          else {
              int temp;
              temp = cell_grid[i][j + 1].status + cell_grid[i][j - 1].status + cell_grid[i + 1][j - 1].status + cell_grid[i + 1][j].status + cell_grid[i + 1][j + 1].status + cell_grid[i - 1][j + 1].status + cell_grid[i - 1][j].status + cell_grid[i - 1][j - 1].status;
              std::cout << temp << "  ";
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
