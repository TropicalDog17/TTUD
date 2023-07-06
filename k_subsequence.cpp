#include <bits/stdc++.h>
#define MAX 100000
int n, k, A, B;
int a[MAX];
using namespace std;
int main() {
  freopen("data1.inp", "r", stdin);

  cin >> n >> k >> A >> B;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int temp;
  int count = 0;
  for (int i = 0; i < n - k; i++) {
    temp = 0;
    for (int j = 0; j < k; j++) {
      temp += a[i + j];
    }

    if (temp >= A && temp <= B) {
      count += 1;
    }
  }
  cout << count;
}