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

// const int M = 1e9 + 7;
// const int N = 1e5 + 3;
// // vvi memo(5002,vi(5002,-1));

// int dpRecur(string s1, string s2, int n, int m, int i, int j)
// {
//     if(i<0){
//         return j+1;
//     }
//     if(j<0){
//         return i+1;
//     }
//     if(memo[i][j]!=-1){
//         return memo[i][j];
//     }
//     if (s1[i] == s2[j])
//     {
//         return memo[i][j]=dpRecur(s1, s2, n, m, i - 1, j - 1);
//     }
//     int ans = INT_MAX;
//     ans = min(ans, 1 + dpRecur(s1, s2, n, m, i, j - 1));
//     ans = min(ans, 1 + dpRecur(s1, s2, n, m, i - 1, j));
//     ans = min(ans, 1 + dpRecur(s1, s2, n, m, i - 1, j - 1));

//     return memo[i][j]= ans;
// }

int dpTable(string s1,string s2,int n,int m){
    vvi dp(n+1,vi(m+1,0));

    for(int i=1;i<=n;i++){dp[i][0]=i;}
    for(int j=1;j<=m;j++){dp[0][j]=j;}

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]== s2[j-1]){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                dp[i][j]= 1+ min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];


}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    // int ans= dpRecur(s1, s2, n, m, n - 1, m - 1);
    int ans= dpTable(s1,s2,n,m);
    c(ans);
    return 0;
}