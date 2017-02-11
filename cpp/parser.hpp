#include <iostream>
#include <vector>
#include <string>

using namespace std;

class parser {
  public:
  parser();
  ~parser();
  vector<string> parse(string s,
                       string delim);
};
