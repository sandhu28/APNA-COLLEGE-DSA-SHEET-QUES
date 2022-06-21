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

int recur(vi &coins,int k){
    int n= coins.size();
    vvi dp(n + 1,vi(k+1,0));
    for(int j=1;j<=k;j++){
        dp[0][j] = 1e9;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j>= coins[i-1]){
                dp[i][j] = min(dp[i][j],1+ dp[i][j-coins[i-1]]);
            }
        }
    }
    return dp[n][k]>= 1e9? -1: dp[n][k];

}

int minimumNumbers(int num, int k)
{
    if (num == 0)
    {
        return 0;
    }
    vi coins;
    for(int i=1;i<=num;i++){
        if(i%10 == k){
            coins.push_back(i);
        }
    }
    return recur(coins,num);
}

int main()
{

    return 0;
}