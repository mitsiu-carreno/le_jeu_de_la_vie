#include "cell.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

  #include <fcntl.h>
  #include <io.h>
  #include <iostream>

  namespace cell{
    void PrintStatus(bool cell_status){
      _setmode(_fileno(stdout), _O_U16TEXT);
      if(cell_status == 1){
        wprintf(cell::states[cell::StateCatalog::alive]);
      }else{
        wprintf(cel::states[cell::StateCatalog::dead]);
      }
    }
  };


#elif defined(__APPLE__) || defined(__linux__)

  #include <iostream>

  namespace cell{
    void PrintStatus(bool cell_status){
      if(cell_status == 1){
        std::cout << cell::states[cell::StateCatalog::alive];
      }else{
        std::cout << cell::states[cell::StateCatalog::dead];
      }
    } 
  };

#else
  // Not supported yet
  #include <stdio.h>

  namespace cell{
    void PrintStatus(bool cellstatus){
      printf("Not supported\n");
    }
  }

#endif
