#ifndef CELL_STATE_H
#define CELL_STATE_H

#include <array>
#include <string>

namespace cell{
  enum StateCatalog{
    dead = 0,
    alive,
  };

  struct Cell{
    bool status;
    std::array<int, 2> coor;
    int id;
    // int coor_x;
    // int coor_y;
  };

  // Position 0 = dead; 1 = alive
  const std::array<char[4], 2> states {{" ","\u2589"}};
  //cell_states[dead] = " ";
  //cell_states[alive] = "\u2589";
};

#endif
