#include <bits/stdc++.h>
using namespace std;
int n, M;
vector<int> a, t, X;
int f;
int cnt = 0;
bool check(int i, int k)
{
    return f + i * a[k] <= M;
}
void Try(int k)
{
    int upper_bound = (M - f - (t[n - 1] - t[k])) / a[k];
    for (int i = 1; i <= upper_bound; i++)

        if (check(i, k))
        {
            X[k] = i;
            f += X[k] * a[k];
            if (k == n - 1)
            {
                if (f == M)
                    cnt += 1;
            }
            else
                Try(k + 1);
            f -= X[k] * a[k];
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> M;
    a.reserve(n);
    t.reserve(n);
    X.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            t[0] = a[0];
        else
        {

            t[i] = t[i - 1] + a[i];
        }
    }
    Try(0);
    cout << cnt << endl;
}
