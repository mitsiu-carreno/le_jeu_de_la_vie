// Includes GetGridSize
#include "cell.hpp"
#include "windowLength.hpp"
#include "grid.hpp"
#include <iostream>
#include <vector>


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
				cell.current_status = true;
				cell.id = contador_id;
				cell_grid[i][j] = cell;
				++contador_id;
			}
		}
		
		DefineInitialStatus(cell_grid.size(), cell_grid);
		
		return cell_grid;
	}
	
	//Funcion que define el new status de las celulas
	int DefineNewStatus(bool cell_status, int neighbours_alive) {
		int new_cell_status;
		if (cell_status == 1) {
			switch (neighbours_alive) {
			case 2:
				new_cell_status = 1;
				break;
			case 3:
				new_cell_status = 1;
				break;
			default:
				new_cell_status = 0;
				break;
			}
		}
		if (cell_status == 0) {
			switch (neighbours_alive) {
			case 2:
				new_cell_status = 1;
				break;
			case 3:
				new_cell_status = 1;
				break;
			default:
				new_cell_status = 0;
				break;
			}
		}
		return new_cell_status;
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
	void PrintGridDebug(std::vector<std::vector<cell::Cell>> &cell_grid){
		for(size_t i{0}; i<cell_grid.size(); ++i){
			for(size_t j{0}; j<cell_grid[i].size(); ++j){
				std::cout << cell_grid[i][j].current_status << " id: " << cell_grid[i][j].id << " - " << j << "," << i << "\n";
			}
		}
	}

// print cell grid function
	void PrintGrid(std::vector<std::vector<cell::Cell>> grid ){
		for(std::vector<cell::Cell> ext_vector : grid ){
			for(cell::Cell cell : ext_vector){
				cell::PrintStatus(cell.current_status);
			}
			std::cout << "\n";
		}
	}

// function to define initial status 
	void DefineInitialStatus (int cell_gridsize, std::vector<std::vector<cell::Cell>> &cell_grid) {
		int status_div {0};
		
		std::cout << "Para definir el estatus inicial de las celulas, escoja un número del 1 al "<< cell_gridsize<<"\n";
		std::cin>> status_div;
		
		for(size_t i{0}; i<cell_grid.size(); ++i){
			for(size_t j{0}; j<cell_grid[i].size(); ++j){
				if (cell_grid[i][j].id%status_div==0){
					cell_grid[i][j].current_status=1;
				} else {
					cell_grid[i][j].current_status=0;
				}
			}
		}
	}

  void CalcNextStatus(std::vector<std::vector<cell::Cell>> &grid){  
    for(size_t y{0}; y<grid.size(); ++y){
      for(size_t x{0}; x<grid[0].size(); ++x){

        int neighbours_alive {GetNeighboursAlive(x, y, grid)};
        std::cout << neighbours_alive << "\n"; // Remove after debugging
        // Process status based neighbour 

		grid[y][x].next_status = DefineNewStatus(grid[y][x].current_status, neighbours_alive);
      }
    }
  }
  

  int GetNeighboursAlive(int cell_x, int cell_y, std::vector<std::vector<cell::Cell>> &grid){
    int neighbours_alive {0};
    int grid_size = static_cast<int>(grid.size()-1);

    int y_upper = (cell_y == 0 ? 0 : cell_y-1);
    int y_lower = (cell_y == grid_size ? grid_size : cell_y+1);
    int x_lefter = (cell_x == 0 ? 0 : cell_x-1);
    int x_righter = (cell_x == grid_size ? grid_size : cell_x+1);

    for(int y{y_upper}; y <= y_lower; ++y){
      for(int x{x_lefter}; x <= x_righter; ++x){
        /* 1)
        if((x != cell_x && cell_y != y) || (x == cell_x && y != cell_y) || (x != cell_x && y == cell_y) ){
          neighbours_alive = neighbours_alive + grid[y][x].current_status; 
        }
        */

        /* 2)
        if(x == cell_x && y == cell_y){
        
        }else{
          neighbours_alive = neighbours_alive + grid[y][x].current_status; 
        }
        */

        if(x != cell_x || y != cell_y){
          neighbours_alive = neighbours_alive + grid[y][x].current_status;
        }
      }
    }
    return neighbours_alive;
  }
}
