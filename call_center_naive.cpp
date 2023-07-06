#include <bits/stdc++.h>
#define MAX 1000000
int n;
int a[MAX];
using namespace std;
int main() {
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i + 1] && a[i] > a[i - 1])
      count += 1;
  }
  cout << count;
}