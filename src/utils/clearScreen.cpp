#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

  #include <windows.h>

namespace utils {
    void ClearScreen() {
        HANDLE                     hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD                      count;
        DWORD                      cellCount;
        COORD                      homeCoords = { 0, 0 };

        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdOut == INVALID_HANDLE_VALUE) {
            return;
        }

        /* Get the number of cells in the current buffer */
        if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
            return;
        }
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        /* Fill the entire buffer with spaces */
        if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR)' ',
            cellCount,
            homeCoords,
            &count
        )
            ) {
            return;
        }

        /* Fill the entire buffer with the current colors and attributes */
        if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count
        )
            ) {
            return;
        }

        /* Move the cursor home */
        SetConsoleCursorPosition(hStdOut, homeCoords);
    }
}
/*
#ifdef _WIN64
// code win 64
#else 
// code win 32
#endif
*/
#elif defined(__APPLE__) || defined(__linux__)

  #include <unistd.h>
  #include <term.h>

  namespace utils{
    void ClearScreen() {
      if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) {
          return;
        }
      }
      char clear[] ="clear";
      
      putp(tigetstr(clear));
    }
  }
/*
#elif __linux__
// code linux
#elfi __unix__
// code unix
#elif defined(_POSIX_VERSION)
// code posix
*/
#else
  // error "Unkown comiler"
  // Not supported yet
  namespace utils{
    void ClearScreen(){
       
    }
  }
#endif

