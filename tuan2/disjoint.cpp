#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int n;
pair<int, int> segments[MAX];
bool compare_segment_greedy(pair<int, int> p1, pair<int, int> p2) {
  return (p1.second < p2.second);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> segments[i].first >> segments[i].second;
  }
  sort(segments, segments + n, compare_segment_greedy);
  int last = segments[0].second;
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (segments[i].first > last) {
      last = segments[i].second;
      count += 1;
    }
  }
  cout << count;
}