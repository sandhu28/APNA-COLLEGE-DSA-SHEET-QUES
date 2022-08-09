#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

// const int M = 1e9 + 7;
// const int N = 1e5 + 3;

int32_t main()
{

    // fast_io;
    int n, q;
    cin >> n >> q;
    vvi arr(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                arr[i][j] += arr[i][j - 1];
                continue;
            }
            if (j == 1)
            {
                arr[i][j] += arr[i - 1][j];
                continue;
            }
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int temp = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
        c(temp);
    }

    return 0;
}