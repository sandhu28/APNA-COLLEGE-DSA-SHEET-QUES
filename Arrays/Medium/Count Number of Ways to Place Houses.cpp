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

// const int M = 1e9 + 7;
const int N = 1e4 + 2;
int M = 1e9 + 7;
// int dp[N][2];
int recur(int n, bool p,vvi &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if(dp[n][p]!=-1){
        return dp[n][p];
    }
    if (p == 0)
    {
        return dp[n][p] = (recur(n - 1, p ^ 1,dp) % M + recur(n - 1, p,dp) % M) % M;
    }
    return dp[n][p]= recur(n - 1, p ^ 1,dp) % M;
}

// int table(int n)
// int countHousePlacements(int n)
// {
//     vvi dp(n+1,vi(2,-1));
//     auto ans = recur(n, 0,dp);
//     return ((ans % M) * 1LL * (ans % M)) % M;
// }

int countHousePlacements(int n)
{
    vvi dp(n+1,vi(2,-1));
    dp[0][0] = dp[0][1] = 1;
    
    for(int i=1;i<=n;i++){
        dp[i][0] = (dp[i-1][0]*1LL+ dp[i-1][1]*1LL)%M;
        dp[i][1] = dp[i-1][0]%M;
    }
    int k = (dp[n-1][0]*1LL + dp[n-1][1])%M;
    return k*k;
}
int main()
{

    return 0;
}