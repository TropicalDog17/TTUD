#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
map<string, int> db;
int main() {
  //   freopen("data1.inp", "r", stdin);
  string s;
  string param;
  while (cin >> s) {
    if (s == "*")
      continue;
    if (s == "find") {
      cin >> param;
      if (db.count(param) == 0) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
      continue;

    } else if (s == "insert") {
      cin >> param;
      if (db.count(param) == 1) {
        cout << 0 << endl;
      } else {
        db[param] = 1;
        cout << 1 << endl;
      }
      continue;
    }
    if (s == "***")
      break;
    db[s] = 1;
  }
}