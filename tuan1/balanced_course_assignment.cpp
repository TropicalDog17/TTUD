#include <bits/stdc++.h>
using namespace std;

int m, n;
int capacity[30];
bool pref[10][30] = {false};
int K;
bool conflict[30][30] = {false};
int s[30] = {-1};
int load[10];
int maximal_load = 30;
// t: teacher, k: kth course -> check if feasible to assign a teacher to a
// course
bool check(int k, int t) {
  if (!pref[t][k])
    return false;
  // Check if any conflicting course is already assigned to this teacher
  for (int i = 0; i < n; i++) {
    if ((conflict[i][k] || conflict[k][i]) && s[i] == t)
      return false;
  }
  return true;
}
int get_maximal_load() { return *max_element(load, load + 10); }
void Try(int k) {
  // cout << k;
  // Check all teacher options.
  cout << k;
  for (int i = 0; i < m; i++) {
    if (check(k, i)) {
      // Assign the teacher
      s[k] = i;
      load[i] += 1;
      // cout << k;
      if (k == m - 1) {
        maximal_load = min(maximal_load, get_maximal_load());
      } else {
        Try(k + 1);
      }
      s[k] = -1;
      load[i] -= 1;
    }
  }
}
int main() {
  cin >> m >> n;
  int pref_count;
  for (int i = 0; i < m; i++) {
    cin >> pref_count;
    for (int j = 0; j < pref_count; j++) {
      int c;
      cin >> c;
      pref[i][c - 1] = true;
    }
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    int course_1, course_2;
    cin >> course_1 >> course_2;
    conflict[course_1 - 1][course_2 - 1] = true;
  }
  Try(0);
  cout << maximal_load;
}
