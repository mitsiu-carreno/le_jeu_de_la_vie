#include <thread>
#include <chrono>

namespace utils{
  void Sleep(int millisec){
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));  
  }
}
