#include "enString.h"
#include <iostream>
using namespace std;

vector<string> split(const string str, const string sep) {
  vector<string> list;
  size_t head = 0;
  while (head < str.length()) {
    size_t found = str.find(sep, head);
    if (found == std::string::npos) {
      list.push_back(str.substr(head));
      break;
    } else {
      list.push_back(str.substr(head, found - head));
      head = found + sep.length();
    }
  }
  return list;
}

string replace(const string str, const string p, const string m) {
  string tmp = str;
  size_t found = tmp.find(p);
  size_t keylen = p.length();
  if (found != std::string::npos) {
    tmp.replace(found, keylen, m);
  }
  return tmp;
}

string replace_all(const string str, const string p, const string m) {
  string tmp = str;
  size_t head = 0;
  size_t keylen = p.length();
  while (head < tmp.length()) {
    size_t found = tmp.find(p, head);
    if (found == std::string::npos) {
      break;
    } else {
      tmp.replace(found, keylen, m);
      head = found + keylen;
    }
  }
  return tmp;
}

bool isStartWith(const string str, const string p) {
  size_t found = str.find(p);
  return found == 0;
}

bool isEndWith(const string str, const string p) {
  size_t found = str.find(p);
  size_t keylen = p.length();
  return (found + keylen) == str.length();
}