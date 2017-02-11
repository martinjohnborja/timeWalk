/**
 *   Title : timeStamp
 */
#include "timeStamp.hpp"
using namespace std;

timeStamp::timeStamp() {
  cout << "Create timeStamp" << endl;
}

timeStamp::~timeStamp() {
  cout << "Destroy timeStamp" << endl;
}

string timeStamp::currentDateTime() {
  now = time(0);
  struct tm tstruct;
  char      buf[80];
  tstruct = *localtime(&now);
  strftime(buf,sizeof(buf),"%Y-%m-%d.%X",&tstruct);
  return buf;
}
