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

int longestArithSeqLength(vector<int> &v)
{
    int n = v.size();
    if (n == 2)
    {
        return n;
    }
    vvi dp(n,vi(1001,0));
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int d = v[i] - v[j]+500;
            dp[i][d]= max(2,dp[j][d]+1);
            mx = max(mx, dp[i][d]);
        }
    }
    return mx;
}

int main()
{

    return 0;
}