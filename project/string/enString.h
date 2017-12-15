#pragma once
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string str, const string sep);

string replace(const string str, const string p, const string m);
string replace_all(const string str, const string p, const string m);

bool isStartWith(const string str, const string p);
bool isEndWith(const string str, const string p);
