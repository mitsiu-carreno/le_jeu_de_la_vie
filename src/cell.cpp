#include "cell.hpp"
#include <iostream>

namespace cell{
  void PrintStatus(bool cell_status){
    if(cell_status == 1){
      std::cout << cell::states[cell::StateCatalog::alive] << "\n";
    }else{
      std::cout << cell::states[cell::StateCatalog::dead] << "\n";
    }
  } 
};
