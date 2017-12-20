#include <iostream>
#include "enString.h"

using namespace std;

int main() {
  vector<string> res = split("1,2,3,4", ",");
  for (size_t i = 0; i < res.size(); ++i) cout << res[i] << '\t';
  cout << endl;

  vector<string> res2 = split("1,2,3,4", ".");
  for (size_t i = 0; i < res2.size(); ++i) cout << res2[i] << '\t';

  cout << endl;

  vector<string> res3 = split("1##2##3##4", "##");
  for (size_t i = 0; i < res3.size(); ++i) cout << res3[i] << '\t';
  cout << endl;

  string str = "abcdefg";
  cout << replace(str, "abc", "1") << endl;

  string str2 = "abcabc";
  cout << replace_all(str2, "ab", "123") << endl;

  string str3 = "abcdefg";
  cout << isStartWith(str3, "bcd") << endl;
  cout << isEndWith(str3, "efg") << endl;

  return 0;
}
