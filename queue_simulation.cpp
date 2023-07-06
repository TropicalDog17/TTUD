#include <bits/stdc++.h>
using namespace std;
queue<string> q;
int main() {
  //   freopen("data1.inp", "r", stdin);
  string s;
  string param;
  while (cin >> s) {
    if (s == "PUSH") {
      cin >> param;
      q.push(param);
      continue;
    } else if (s == "POP") {
      if (q.empty()) {
        cout << "NULL" << endl;
        continue;
      } else {
        cout << q.front() << endl;
        q.pop();
        continue;
      }
    } else {
      break;
    }
  }
  return 0;
}