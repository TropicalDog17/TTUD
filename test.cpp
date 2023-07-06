// Thuat toan sinh ke tiep
//  Tap con
#include <iostream>
using namespace std;
#include <iomanip>

// Ham in ket qua
void ket_qua(int *a, int &dem, int k) {
  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
  // dem++;
  cout << endl;
}
// Ham sinh day ke tiep
void ham_sinh(int *a, int n, int k, int &stop) {
  int i = k - 1;
  while (i >= 0 && a[i] == n - k + i + 1) {
    i--;
  }
  if (i >= 0) {
    a[i]++;
    for (int j = i + 1; j < k; j++) {
      a[j] = a[i] + j - i;
    }
  } else {
    stop = 1;
  }
}

void xu_ly(int *a, int n, int k, int &stop, int &dem) {
  while (!stop) {
    ham_sinh(a, n, k, stop);
    if (stop == 1) {
      cout << -1;
      return;
    }
    ket_qua(a, dem, k);
  }
}

int n, k;

int main() {
  freopen("data.inp", "r", stdin);

  cin >> n >> k;
  int *a;
  a = new int[k];
  for (int i = 0; i < k; i++)
    cin >> a[i];

  int stop = 0, dem = 1;
  xu_ly(a, n, k, stop, dem);

  return 0;
}