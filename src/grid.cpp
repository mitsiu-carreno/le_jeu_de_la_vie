// Includes GetGridSize
#include "cell.hpp"
#include<iostream>
#include<vector>
#include "windowLength.hpp"

// Include PrintGrid


// GetGridSize

//OBTENER DIMENSIONES DE LA PANTALLA  

std::array<int,2>  GetGridSize ( ){
	std::array<int,2> col_row {utils::GetWindowLength()};//col, row
	std::array<int,2> tamanio_grid_ajustado; 
	bool ancho=false;
	if (col_row [0]>col_row [1]) //col>row
		{
			ancho=true;
		} else if (col_row [0]==col_row [1]) //col=row
		{
			ancho=true;
		} else if (col_row [0]<col_row [1]) //col<row
		{
			ancho=false;
		}
	if (ancho==true){
		tamanio_grid_ajustado[0]= col_row[1]*.9;
		tamanio_grid_ajustado[1]= col_row[1]*.9;
	} else {
		tamanio_grid_ajustado[0]= col_row[0]*.9;
		tamanio_grid_ajustado[1]= col_row[0]*.9;
	}
	return tamanio_grid_ajustado;
}

void PrintGridDebug(std::vector<std::vector<cell::Cell>> cell_grid){  
  for(size_t i{0}; i<cell_grid.size(); ++i){
    for(size_t j{0}; j<cell_grid[i].size(); ++j){
      std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << "\n";
    }
  }
}


// PrintGrid
void PrintGrid(std::vector<std::vector<cell::Cell>> grid ){

	for(std::vector<cell::Cell> ext_vector : grid ){
		
		for(cell::Cell cell : ext_vector){
			
			cell::PrintStatus(cell.status);
		}
		std::cout << "\n";
	}
}

// Check cell status
void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid){
	
	for(size_t i {0} ; i < grid.size() ; ++i){
	
		for(size_t j {0}; j < grid[i].size(); ++j ){
 
                        std::cout << grid[i][j].id - 1 << " -> " << grid[i][j].id << " <- " << grid[i][j].id + 1 << "\n";
		
		}
	}
}

/*cambiar a un for normal 
grid[x-1][y-1]
grid[x-1][y-1].status
if (grid[x][y].id == id_busqueda){
obtener status
y-1 devuelve cel, esta cell tiene status 
grid[x-1][y-1]
 */

