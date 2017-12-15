#include <iostream>
#include "enString.h"

using namespace std;

int main() {
  vector<string> res = split("1,2,3,4", ",");
  for (string &x : res) cout << x << '\t';
  cout << endl;

  vector<string> res2 = split("1,2,3,4", ".");
  for (string &x : res2) cout << x << '\t';
  cout << endl;

  vector<string> res3 = split("1##2##3##4", "##");
  for (string &x : res3) cout << x << '\t';
  cout << endl;

  string str = "abcdefg";
  cout << replace(str, "abc", "1") << endl;

  string str2 = "abcabc";
  cout << replace_all(str2, "ab", "123") << endl;

  string str = "abcdefg";
  cout << isStartWith(str, "bcd") << endl;
  cout << isEndWith(str, "efg") << endl;

  return 0;
}
