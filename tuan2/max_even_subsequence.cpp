#include <bits/stdc++.h>
#define MAX 1000000
int n;
long a[MAX];
long f[MAX][2];
using namespace std;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(f, INT_MIN, sizeof(f));
  if (a[0] % 2 == 0)
    f[0][0] = a[0];
  else {
    f[0][1] = a[0];
  }
  for (int i = 1; i < n; i++) {

    if (a[i] % 2 == 0) {
      f[i][0] = max(f[i - 1][0] + a[i], a[i]);
      f[i][1] = f[i - 1][1] + a[i];
    } else {
      f[i][0] = f[i - 1][1] + a[i];
      f[i][1] = max(f[i - 1][0] + a[i], a[i]);
    }
  }
  long max_val = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (max_val < f[i][0])
      max_val = f[i][0];
  }
  cout << max_val;
}