#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
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

const int M = 1e9 + 7;
const int N = 1e5 + 3;

bool recur(int i, vi &v, int n, vi &dp)
{
    if (i > n - 1)
    {
        return 1;
    }
    if (n - i < 2)
    {
        return 0;
    }
    if (n - i == 2)
    {
        if (v[i + 1] == v[i])
        {
            return 1;
        }
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int d1 = v[i + 1] - v[i];
    int d2 = v[i + 2] - v[i + 1];
    if (d1 == 0)
    {
        if (recur(i + 2, v, n, dp))
        {
            return dp[i] = 1;
        }
    }
    if (d1 == 0 && d2 == 0)
    {
        if (recur(i + 3, v, n, dp))
        {
            return dp[i] = 1;
        }
    }
    if (d1 == 1 && d2 == 1)
    {
        if (recur(i + 3, v, n, dp))
        {
            return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}

bool dp_table(vi &v)
{
    int n = v.size();
    vi dp(n + 1, 0);
    dp[n] = 1;
    if (v[n - 2] == v[n - 1])
    {
        dp[n - 2] = 1;
    }
    for (int i = n - 3; i >= 0; i--)
    {
        int d1 = v[i + 1] - v[i];
        int d2 = v[i + 2] - v[i + 1];
        if (d1 == 0)
        {
            if (dp[i+2])
            {
                dp[i]=1;
                continue;
            }
        }
        if (d1 == 0 && d2 == 0)
        {
            if (dp[i+3]==1)
            {
                dp[i] = 1;
                continue;
            }
        }
        if (d1 == 1 && d2 == 1)
        {
            if (dp[i+3]==1)
            {
                dp[i] = 1;
            }
        }
    }
    return dp[0];
}

bool validPartition(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n, -1);
    return recur(0, v, n, dp);
    // return 0;
}

int main()
{

    return 0;
}