#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) 
  #include <windows.h>

  namespace utils{
    int GetWindowLength(){
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      int columns, rows;

      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
      rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
      return columns;
    }
  }

#elif defined(__APPLE__) || defined(__linux__)

  #include <sys/ioctl.h>
  #include <unistd.h>
  
  namespace utils{
    int GetWindowLength(){
        
      struct winsize size;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
      //std::cout << size.ws_col << "\n";
      //std::cout << size.ws_row << "\n";
      return size.ws_col;
    }
  }      
#else
  // Not supported yet
  namespace utils{
    int GetWindowLength(){
      return -1;
    }
  }

#endif
