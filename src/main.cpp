#include "cell.hpp"
#include "grid.hpp"
#include "windowLength.hpp"
#include "clearScreen.hpp"
#include "sleepThread.hpp"
#include "initialState.hpp"
#include <iostream>
#include <vector>

/////////------
void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid){ 
	
	for(size_t i {0} ; i < grid.size() ; ++i){
	
		for(size_t j {0}; j < grid[i].size(); ++j ){

			std::cout << grid[i][j].id - 1 << " -> " << grid[i][j].id << " <- " << grid[i][j].id + 1 << "\n";

		}
	}
}


/*cambiar a un for normal 
 * grid[x-1][y-1]
 * grid[x-1][y-1].status
 * if (grid[x][y].id == id_busqueda){
// obtener status
 * y-1 devuelve cel, esta cell tiene status 
 * grid[x-1][y-1]
 * 
 * */
/////////------

int main(){
  /////////------
  std::array<int,2> tamanio_grid=GetGridSize ( );
  int side_grid = tamanio_grid[0];
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

  PrintGridDebug(cell_grid);

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
          else if (i > 0 && i < cell_grid.size() - 1 && j == static_cast<size_t>(size)-1) {  // lateral derecha 
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

  /////////------
  //std::cout << "window length: " << utils::GetWindowLength() << "\n";

  // utils::ClearScreen();
  CheckCellStatus(cell_grid);

  PrintGrid(cell_grid);

  DefineInitialStatus(cell_grid.size(), cell_grid);

 
	return 0;
  
}
