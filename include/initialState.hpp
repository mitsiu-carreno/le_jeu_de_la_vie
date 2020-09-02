#ifndef INITIAL_STATE_H
#define INITIAL_STATE_H

#include <array>
#include <string>
#include <vector>
#include "cell.hpp"
#include<iostream>
#include<string>


void DefineInitialStatus (int cell_gridsize){

int status_div {0};

std::cout << "Para definir el estatus inicial de las celulas, escoja un número del 1 al"<< cell_gridsize<<"\n"; 
std::cin>> status_div;
for(size_t i{0}; i< cell_grid.size(); ++i){
     for(size_t j{0}; j<cell_grid[i].size(); ++j){
       if (cell_grid[i][j].id/status_div==0){
           cell_grid[i][j].status=1;
           } else 
           {
             cell_grid[i][j].status=0;  
           }
    }
}
}




#endif