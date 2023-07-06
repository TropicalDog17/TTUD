#include <bits/stdc++.h>
#define MAX 1000000
int n;
using namespace std;
int main() {
  cin >> n;
  int count = 0, temp;
  int a[3];
  for (int i = 0; i < n; i++) {
    if (i <= 2) {
      cin >> a[i];
      if (i == 2 && a[1] > a[2] && a[1] > a[0])
        count = 1;
    } else {
      // shifting the window
      temp = a[1];
      a[1] = a[2];
      a[0] = temp;
      cin >> a[2];
      if (a[1] > a[2] && a[1] > a[0])
        count += 1;
    }
  }
  cout << count;
}