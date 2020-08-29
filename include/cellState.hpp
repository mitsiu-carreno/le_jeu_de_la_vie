#ifndef CELL_STATE_H
#define CELL_STATE_H

#include <array>
#include <string>

enum CellStateCatalog{
  dead = 0,
  alive,
};

// Position 0 = dead; 1 = alive
const std::array<char[4], 2> cell_states {{" ","\u2589"}};
//cell_states[dead] = " ";
//cell_states[alive] = "\u2589";

#endif
