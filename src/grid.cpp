// Includes GetGridSize
#include "cell.hpp"
#include "windowLength.hpp"
#include "grid.hpp"
#include<iostream>
#include<vector>


// Include PrintGrid


// GetGridSize

//OBTENER DIMENSIONES DE LA PANTALLA

namespace Grid {
	
	std::vector<std::vector<cell::Cell>> Initialize_Grid (){
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
		
		DefineInitialStatus(cell_grid.size(), cell_grid);
		
		return cell_grid;
	}
	
	std::array<int,2> GetGridSize ( ){
		
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
		
		if (ancho==true)
		{
			tamanio_grid_ajustado[0]= col_row[1]*.9;
			tamanio_grid_ajustado[1]= col_row[1]*.9;
		} else {
			tamanio_grid_ajustado[0]= col_row[0]*.9;
			tamanio_grid_ajustado[1]= col_row[0]*.9;
		}
		return tamanio_grid_ajustado;
	}

// dbg function
	void PrintGridDebug(std::vector<std::vector<cell::Cell>> cell_grid){
		for(size_t i{0}; i<cell_grid.size(); ++i){
			for(size_t j{0}; j<cell_grid[i].size(); ++j){
				std::cout << cell_grid[i][j].status << " id: " << cell_grid[i][j].id << " - " << cell_grid[i][j].coor[0] << "," << cell_grid[i][j].coor[1] << "\n";
			}
		}
	}

// print cell grid function
	void PrintGrid(std::vector<std::vector<cell::Cell>> grid ){
		for(std::vector<cell::Cell> ext_vector : grid ){
			for(cell::Cell cell : ext_vector){
				cell::PrintStatus(cell.status);
			}
			std::cout << "\n";
		}
	}

// function to define initial status 
	void DefineInitialStatus (int cell_gridsize, std::vector<std::vector<cell::Cell>> & cell_grid) {
		int status_div {0};
		
		std::cout << "Para definir el estatus inicial de las celulas, escoja un número del 1 al "<< cell_gridsize<<"\n";
		std::cin>> status_div;
		
		for(size_t i{0}; i<cell_grid.size(); ++i){
			for(size_t j{0}; j<cell_grid[i].size(); ++j){
				if (cell_grid[i][j].id%status_div==0){
					cell_grid[i][j].status=1;
				} else {
					cell_grid[i][j].status=0;
				}
			}
		}
	}

// developing ... check cell status function
	void CheckCellStatus(std::vector<std::vector<cell::Cell>> grid){
		for(size_t i {0} ; i < grid.size() ; ++i){
			for(size_t j {0}; j < grid[i].size(); ++j ){
				std::cout << grid[i][j].id - 1 << " -> " << grid[i][j].id << " <- " << grid[i][j].id + 1 << "\n";
			}
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

