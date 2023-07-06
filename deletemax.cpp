#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> result;
priority_queue<int> pq;
int main() {
  freopen("data1.inp", "r", stdin);
  cin >> n;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    pq.push(temp);
  }
  string str;
  int param;
  while (cin >> str) {
    if (str == "insert") {
      cin >> param;
      pq.push(param);
    } else if (str == "delete-max") {
      result.push_back(pq.top());
      pq.pop();
    } else {
      break;
    }
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i) << endl;
  }
}