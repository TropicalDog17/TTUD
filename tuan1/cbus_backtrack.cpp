#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[23][23];
bool visited[23];
int s[23];
int final_res = INT_MAX;
bool check(int v, int load) {
  if (visited[v])
    return false;
  if (load == 0 && v > n)
    return false;
  if (load == k && v <= n)
    return false;
  if (v > n && !visited[v - n])
    return false; // Chua len xe thi khong xuong o diem don dc

  return true;
}
void backtrack(int pos, int load, int sum) {
  if (pos == 2 * n) {
    final_res = min(final_res, sum + c[s[pos - 1]][0]);
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (check(i, load)) {
      visited[i] = true;
      s[pos] = i;
      int new_load = load + (i <= n ? 1 : -1);
      int new_sum = sum + (pos == 0 ? c[0][i] : c[s[pos - 1]][s[pos]]);
      if (new_sum < final_res)
        backtrack(pos + 1, new_load, new_sum);
      visited[i] = false;
      s[pos] = 0;
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> c[i][j];
    }
  }

  memset(visited, false, sizeof(visited));
  backtrack(0, 0, 0);

  cout << final_res << endl;

  return 0;
}