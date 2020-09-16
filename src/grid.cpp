// Includes GetGridSize
#include "cell.hpp"
#include<iostream>
#include<vector>

// Include PrintGrid


// GetGridSize








// PrintGrid
void PrintGrid(std::vector<std::vector<cell::Cell>> grid ){

	for(std::vector<cell::Cell> ext_vector : grid ){
		
		for(cell::Cell cell : ext_vector){
			
			cell::PrintStatus(cell.status);
		}
		std::cout << "\n";
	}
}


