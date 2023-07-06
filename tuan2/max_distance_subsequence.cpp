#include <bits/stdc++.h>
#define MAX 100000
int T, N, C;
int a[MAX];
using namespace std;
// Check if we can put C cows with distance d
bool check(int d) {
  int count = 1;
  int last = a[0];
  for (int i = 1; i < N; i++) {
    if (a[i] - last >= d) {
      count += 1;
      last = a[i];
    }
  }
  return count >= C;
}
int main() {
  cin >> T;
  while (T > 0) {
    cin >> N >> C;
    for (int i = 0; i < N; i++)
      cin >> a[i];

    // Solve this!

    // Sort the array in increasing order.
    sort(a, a + N - 1);
    // Maximum distance between 2 elements
    int end = a[N - 1] - a[0];
    int start = 0;
    int mid;
    int result = 0;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (check(mid)) {
        result = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    cout << result << endl;
    T -= 1;
  }
}