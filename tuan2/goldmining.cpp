#include <bits/stdc++.h>
#define MAX 1000000
int N, L1, L2;
int a[MAX];
int F[MAX];
using namespace std;

int dp(int i) {
  if (i < L1)
    F[i] = a[i];
  if (F[i] > 0)
    return F[i];
  int max = 0;
  for (int j = i - L2; j <= i - L1; j++) {
    if (j >= 0 && dp(j) > max)
      max = dp(j);
  }
  F[i] = a[i] + max;
  return F[i];
}
int main() {
  cin >> N >> L1 >> L2;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int max = 0;
  for (int i = 0; i < N; i++) {
    if (dp(i) > max)
      max = dp(i);
  }
  cout << max;
}