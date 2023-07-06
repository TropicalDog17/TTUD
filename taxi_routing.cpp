// C++ implementation of the approach taxi routing
#include <bits/stdc++.h>
#define MAX 11
int n;
int a[MAX][MAX];
using namespace std;
void tsp(vector<bool> &v, int currPos, int n, int count, int cost, int &ans) {

  if (count == 2 * n + 1 && a[currPos][0]) {
    ans = min(ans, cost + a[currPos][0]);
    return;
  }

  for (int i = 1; i <= 2 * n; i++) {
    bool is_not_two_passengers = i % n != currPos % n;
    if (!v[i] && a[currPos][i] && is_not_two_passengers) {
      v[i] = true;
      tsp(v, i, n, count + 1, cost + a[currPos][i], ans);

      v[i] = false;
    }
  }
};

int main() {
  cin >> n;
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> a[i][j];
    }
  }

  vector<bool> v(2 * n + 1);
  for (int i = 0; i <= 2 * n; i++)
    v[i] = false;

  v[0] = true;
  int ans = INT_MAX;

  tsp(v, 0, n, 1, 0, ans);

  cout << ans;

  return 0;
}