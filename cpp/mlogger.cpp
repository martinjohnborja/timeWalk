/**
 *  To code :
 *  1.) threaded logger
 *  2.) current date time 
 *  3.) parser
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <vector>
#include "parser.hpp"
#include "timeStamp.hpp"
using namespace std;

class threadedLogger {
  private:
  ifstream keyfile;
  char* logName;
  public:
  threadedLogger();
  ~threadedLogger();
  void startLog(char* keyname);
  void setLogName(char* logname);
  void playAlarm(char* alarmname);
};  

threadedLogger::threadedLogger() {
  cout << "Construct threadedLogger" << endl;
}

threadedLogger::~threadedLogger() {
  cout << "Detroy threadedLogger" << endl;
}

void threadedLogger::setLogName(char* logname) {
  this->logName = logname;
}

void threadedLogger::playAlarm(char* alarmname) {
  timeStamp      tms;
  parser         p;
  vector<string> v;
  ifstream       alarmfile;
  string         alarm = "";
  alarmfile.open(alarmname);
  while(getline(alarmfile,alarm)) {
    v = p.parse(alarm,"<<<");
    do {
    }
    while(tms.currentDateTime() != v[0]);
    cout << endl << "============================================================" << endl;
    cout << v[1] << endl;
    cout << "============================================================" << endl;
  }
}

void threadedLogger::startLog(char* keyname) {
  timeStamp tms;
  ofstream  outfile;
  ifstream  keyfile;
  string    instr = "";
  string    input = "";
  string    intro = "PMLog\n-----\n";
  outfile.open(this->logName);
  cout << intro;
  outfile << intro;

  while(instr != "exit") {
    cout << tms.currentDateTime() << ": ";
    getline(cin,instr);
    if(instr == "?") {
      keyfile.open(keyname);
      while(getline(keyfile,input)) {
        cout << input << endl;
      }
      keyfile.close();
    }
    else {
      outfile << tms.currentDateTime() << ": ";
      outfile << instr << endl;
    }
  }
  outfile.close();
}

// logs
void tlog (char* log,
           char* key) {
  threadedLogger t1;
  t1.setLogName(log);
  t1.startLog(key);
}

// notifies alarms
void alarm (char* alarm) {
  threadedLogger t2;
  t2.playAlarm(alarm);
}

int main(int argc, char* argv[]) {
  thread logger (tlog,argv[1],argv[2]);
  thread alrm (alarm,argv[3]);

  logger.join();
  return 0;
}
