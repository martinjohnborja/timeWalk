/**
 *   Title: timeStamp
 */
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class timeStamp {
  private:
  time_t now;
  public:
  timeStamp();
  ~timeStamp();
  string currentDateTime();
};
