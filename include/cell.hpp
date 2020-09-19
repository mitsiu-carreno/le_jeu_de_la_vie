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
  //const std::array<char[4], 2> states {{" ","\u2589"}};
  //cell_states[dead] = " ";
  //cell_states[alive] = "\u2589";

  // const std::array<const wchar_t*, 2> states{{L" ", L"\n2588"}};

  void PrintStatus(bool cell_status);
};

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  namespace cell{
    const std::array<const wchar_t*, 2> states{{L" ", L"\n2588"}};
  };

#elif defined(__APPLE__) || defined(__linux__)
  namespace cell{
    const std::array<char[4], 2> states {{" ","\u2589"}};
  };
#endif

#endif
