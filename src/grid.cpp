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

 



// PrintGrid
void PrintGrid(std::vector<std::vector<cell::Cell>> grid ){

	for(std::vector<cell::Cell> ext_vector : grid ){
		
		for(cell::Cell cell : ext_vector){
			
			cell::PrintStatus(cell.status);
		}
		std::cout << "\n";
	}
}


