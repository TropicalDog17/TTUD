#include <bits/stdc++.h>
#define MAX 1000000
#define MODULO 1000000007

int n;
int a[MAX];
int memo[MAX] = {0};
using namespace std;
int dp(int k) {
  if (k == 1) {
    if (a[0] > a[1])
      memo[1] = 1;
    return memo[1];
  }
  if (k > 1 && memo[k] != 0) {

    return memo[k];
  }
  int count = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] > a[k])
      count += 1;
  }
  memo[k] = (dp(k - 1) + count) % MODULO;
  return memo[k];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << dp(n - 1);
}