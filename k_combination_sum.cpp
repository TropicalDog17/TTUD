#include <bits/stdc++.h>
#define MAX 100000
int n;
int a[MAX];
int dp[MAX] = {0};
using namespace std;
int dyn(int i) {
  if (i == 0) {
    dp[0] = a[0];
    return dp[0];
  } else if (i == 1) {
    dp[1] = a[0] + a[1];
    return dp[1];
  } else if (i == 2) {
    dp[2] = max(a[0], a[1]) + a[2];
    return dp[2];
  }
  dp[i] = max(dyn(i - 2) + a[i], dyn(i - 1));
  return dp[i];
}
int main() {
  freopen("data1.inp", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << dyn(6);
}