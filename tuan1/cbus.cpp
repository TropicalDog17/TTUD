#include <bits/stdc++.h>
int n, K;
int c[23][23];
bool appear[22] = {false};
int s[22];
int load = 0;
int final_res = INT_MAX;
int sum = 0;
using namespace std;
bool check(int v) {
  if (appear[v])
    return false;
  if (load == 0 && v > n)
    return false;
  if (load == K && v <= n)
    return false;
  if (v > n && !appear[v - n])
    return false; // Chua len xe thi khong xuong o diem don dc

  return true;
}

void Try(int k) {
  for (int i = 1; i <= 2 * n; i++) {
    if (check(i)) {
      appear[i] = true;
      s[k] = i;
      if (i <= n) {
        load += 1;
      } else {
        load -= 1;
      }
      if (k == 0)
        sum += c[0][i];
      else
        sum += c[s[k - 1]][s[k]];

      if (k == 2 * n - 1) {

        if (sum + c[s[k]][0] < final_res) {
          final_res = sum + c[s[k]][0];
          cout << final_res;
          for (int j = 1; j < 2 * n; j++) {
            cout << s[j - 1] << s[j];
            cout << c[s[j - 1]][s[j]];
            cout << endl;
          }
          cout << endl;
        }
      } else {
        if (sum >= final_res)
          continue;
        Try(k + 1);
      }

      appear[i] = false;
      if (i <= n) {
        load -= 1;
      } else {
        load += 1;
      }
      if (k == 0)
        sum -= c[0][i];
      else
        sum -= c[s[k - 1]][i];
    }
  }
}
int main() {
  cin >> n >> K;
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> c[i][j];
    }
  }
  Try(0);
  cout << final_res << endl;
}
