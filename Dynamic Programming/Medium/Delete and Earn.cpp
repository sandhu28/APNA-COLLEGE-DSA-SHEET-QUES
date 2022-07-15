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

int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[nums[i]] += nums[i];
    }
    n = m.size();
    vi vec;
    for (auto &e : m)
    {
        vec.push_back(e.first);
    }
    for (int i = 0; i < n; i++)
    {
        z(vec[i]);
    }
    vvi dp(n + 1, vi(2, 0));
    for (int i = 1; i <= n; i++)
    {
        if ((i < n) && (vec[i] - vec[i - 1] > 1))
        {
            dp[i][0] = dp[i][1] = max(dp[i - 1][0], m[vec[i - 1]] + dp[i - 1][1]);
        }
        else
        {
            // c("yes");
            dp[i][0] = max(dp[i - 1][0], m[vec[i - 1]] + dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0];
        }
    }
    return max(dp[n][0], dp[n][1]);
    // return 1;
}

int main()
{

    return 0;
}