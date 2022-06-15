#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;
int dp[N][101];

int ValidArrays(int n, int m, vi &v)
{
    for (int j = 1; j <= m; j++)
    {
        if (v[0] == 0)
        {
            dp[0][j] = 1;
        }
        else
        {
            if (j == v[0])
            {
                dp[0][j] = 1;
            }
            else
            {
                dp[0][j] = 0;
            }
        }
    }
    lli ret = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            lli ans = 0;
            if ((v[i] == 0) || (j == v[i]))
            {
                ans += dp[i - 1][j];
                if (j - 1 >= 0 && j - 1 <= m)
                {
                    ans += (dp[i - 1][j - 1]);
                }
                if (j + 1 >= 0 && j + 1 <= m)
                {
                    ans += (dp[i - 1][j + 1]);
                }
            }
            dp[i][j] = ans % M;
            // ret = max(ret, 1LL * dp[i][j]);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        (ret += dp[n-1][j]) %= M;
    }
    return ret;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    c(ValidArrays(n, m, v));

    return 0;
}