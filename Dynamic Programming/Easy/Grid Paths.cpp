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
const int N = 1e3 + 2;
char arr[N][N];
int dp[N][N];

int dp_tab(int n){
    if(arr[0][0]== '*'){
        return 0;
    }
    dp[0][0]= 1;
    for (int i = 1; i < n; i++){
        if(arr[i][0]=='*'){
            dp[i][0] = 0;
            continue;
        }
        dp[i][0]= dp[i-1][0];
    }
    for (int j = 1; j < n; j++){
        if(arr[0][j]=='*'){
            dp[0][j]==0;continue;
        }
        dp[0][j]=dp[0][j-1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][j]== '*'){
                dp[i][j] =0;
            }
            else{
                dp[i][j] = (dp[i-1][j]%M + dp[i][j-1]%M)%M;
            }
        }
    }
    return dp[n-1][n-1];

}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    c(dp_tab(n));


    return 0;
}