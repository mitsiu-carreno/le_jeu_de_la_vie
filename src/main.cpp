#include "cell.hpp"
#include "grid.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include "initialState.hpp"
#include <iostream>
#include <vector>

int CellNewStatus(int cell_status, int status_vecinos) {
    int new_cell_status;
    if (cell_status == 1) {
        switch (status_vecinos) {
            case 2:
                new_cell_status = 1;
                break;
            case 3:
                new_cell_status = 1;
            default:
                new_cell_status = 0;
        }
    }
    if (cell_status == 0) {
        switch (status_vecinos) {
        case 2:
            new_cell_status = 1;
            break;
        case 3:
            new_cell_status = 1;
        default:
            new_cell_status = 0;
        }
    }
    return new_cell_status;
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
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1];
      //PrintStatus(cell_grid[i][j].status);
    }
    std::cout << "\n";
  }

  for (size_t i{ 0 }; i < cell_grid.size(); ++i) {
      for (size_t j{ 0 }; j < cell_grid.size(); ++j) {
          int size { static_cast<int>(cell_grid.size())}; // obtiene el tamaño de la matriz para futuros calculos

          if (cell_grid [i][j].id == 1) { //esquina arriba-izquierda
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j + 1].status + cell_grid[i+1][j + 1].status + cell_grid[i+1][j].status;

              std::cout << cell_grid[i][j].status <<"  ";
              cell_grid[i][j].status = CellNewStatus(cell_status,suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (cell_grid [i][j].id > 1 && cell_grid [i][j].id < size) { // central arriba
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j + 1].status + cell_grid[i + 1][j + 1].status + cell_grid[i + 1][j].status + cell_grid[i + 1][j-1].status + cell_grid[i][j - 1].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (cell_grid [i][j].id == size) { // esquina arriba-derecha
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j - 1].status + cell_grid[i + 1][j - 1].status + cell_grid[i + 1][j].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (cell_grid [i][j].id == size * size - (size - 1)) { // esquina abajo-izquierda
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i-1][j].status + cell_grid[i - 1][j + 1].status + cell_grid[i][j+1].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (cell_grid [i][j].id > size* size - (size - 1) && cell_grid [i][j].id < size * size) {  // cental abajo
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j-1].status + cell_grid[i-1][j-1].status + cell_grid[i-1][j].status + cell_grid[i-1][j+1].status + cell_grid[i][j+1].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (cell_grid [i][j].id == size * size) { // esquina abajo-derecha
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j-1].status + cell_grid[i-1][j-1].status + cell_grid[i-1][j].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (i > 0 && i < cell_grid.size()-1 && j == 0) { //  lateral izquierda
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i-1][j].status + cell_grid[i-1][j+1].status + cell_grid[i][j+1].status + cell_grid[i+1][j+1].status + cell_grid[i+1][j].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else if (i > 0 && i < cell_grid.size() - 1 && j == size-1) {  // lateral derecha 
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i-1][j].status + cell_grid[i-1][j-1].status + cell_grid[i][j-1].status + cell_grid[i+1][j-1].status + cell_grid[i+1][j].status;

              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
          }
          else {
              int suma_status_vecinos;
              int cell_status{ cell_grid[i][j].status };
              suma_status_vecinos = cell_grid[i][j + 1].status + cell_grid[i][j - 1].status + cell_grid[i + 1][j - 1].status + cell_grid[i + 1][j].status + cell_grid[i + 1][j + 1].status + cell_grid[i - 1][j + 1].status + cell_grid[i - 1][j].status + cell_grid[i - 1][j - 1].status;
              
              std::cout << cell_grid[i][j].status << "  ";
              cell_grid[i][j].status = CellNewStatus(cell_status, suma_status_vecinos);
              std::cout << cell_grid[i][j].status << "  ";
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
