#include "parser.hpp"
using namespace std;

parser::parser() {
  cout << "Create parser" << endl;
}

parser::~parser() {
  cout << "Destroy parser" << endl;
}

vector<string> parser::parse(string s,
                             string delim) {
  vector<string> sv;
  string token;
  size_t pos = 0;
  while((pos = s.find(delim)) != string::npos) {
    token = s.substr(0,pos);
    //cout << token << endl;
    sv.push_back(token);
    s.erase(0,pos + delim.length());
  }
  //cout << s << endl;
  sv.push_back(s);
  return sv;
}
