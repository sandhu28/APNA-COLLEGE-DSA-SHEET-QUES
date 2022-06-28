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
#define all(x) (x).begin(), (x).end()
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

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
#define all(x) (x).begin(), (x).end()
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int recur(int n, int i, int M, int p, int pp, vector<vvi> &dp)
{
    if (i == n)
    {
        return 1;
    }
    if (dp[i][p][pp] != 0)
    {
        return dp[i][p][pp];
    }
    int ans = 0;
    for (int j = 1; j <= 6; j++)
    {
        if (i == 0)
        {
            p = j;
            ans = (ans % M) + (recur(n, i + 1, M, p, pp, dp) % (M));
        }
        else
        {
            if ((j == p) || (j == pp) || (p != 0 && (__gcd(p, j) != 1)))
            {
                continue;
            }
            ans = (ans % M) + (recur(n, i + 1, M, j, p, dp) % (M));
        }
    }
    return dp[i][p][pp] = ans % M;
}
int distinctSequences(int n)
{
    vi v(n);
    vector<vector<vector<int>>> dp(1e4 + 1, vvi(7, vi(7, 0)));
    return recur(n, 0, 1e9 + 7, 0, 0, dp);
}

int main()
{
    int n;
    cin >> n;
    int ans = distinctSequences(n);
    c(ans);
    return 0;
}