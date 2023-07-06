    #include <bits/stdc++.h>
    using namespace std;
    int cnt = 0;
    int digits[8]; // NULL, H, U, S, T , O, I, C

    // check for all permutaion of selected digits.
    void check(int digits[], int n) {
    do {
        // H or S must not be zero
        if (digits[1] == 0 || digits[3] == 0)
        continue;
        int hust = 1000 * digits[1] + 100 * digits[2] + 10 * digits[3] + digits[4];
        int soict = 10000 * digits[3] + 1000 * digits[5] + 100 * digits[6] +
                    10 * digits[7] + digits[4];
        // cout << hust << soict << endl;
        if (hust + soict == n)
        cnt += 1;
    } while (next_permutation(digits + 1, digits + 8));
    }

    // Try to update digits as increasing sequence, consist of seven number(start at
    // index 1).
    void Try(int k, int n) {
    for (int i = digits[k - 1] + 1; i < k + 3; i++) {
        digits[k] = i;
        if (k == 7) {
        check(digits, n);
        for (int j = 1; j < 8; j++) {
            cout << digits[j];
        }
        cout << endl;
        } else {
        Try(k + 1, n);
        digits[k] = 0;
        }
    }
    }
    int main() {
    int n;
    //   cin >> n;
    //   if (n > 98765 + 9876 || n < 10000 + 1000) {
    //     cout << 0;
    //     return 0;
    //   }
    n = 78952;
    digits[0] = -1;
    Try(1, n);
    cout << cnt;
    return 0;
    }