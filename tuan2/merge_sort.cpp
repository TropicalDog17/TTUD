#include <bits/stdc++.h>
using namespace std;
int A[100];

// Merge A[p, q] to A[q+1, r];
void swap(int A[], int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
void merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1, n2 = r - q;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = A[p + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = A[q + 1 + j];
  }

  // Merge the temporary arrays back into A
  int i = 0; // Initial index of first subarray
  int j = 0; // Initial index of second subarray
  int k = p; // Initial index of merged subarray

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}
void merge_sort(int A[], int p, int r) {
  int q;
  if (p < r) {
    q = (p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}
int main() {
  cout << "Hello world";
  int A[9] = {3, 2, 6, 4, 5, 8, 7, 1, 0};
  merge_sort(A, 0, 8);
  for (int i = 0; i < 9; i++) {
    cout << A[i];
  }
}