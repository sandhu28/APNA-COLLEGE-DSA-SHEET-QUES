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

int stoneGameVII(vector<int> &stones)
{
    int n = stones.size();
    vi prefix(n);
    prefix[0]= stones[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + stones[i];
    }
    vvi dp(n,vi(n,0));
    for(int g=1;g<n;g++){
        for(int j=g,i=0;j<n;j++,i++){
            if(g==1){
                dp[i][j]= max(stones[i],stones[j]);
            }
            else{
                dp[i][j]= max((prefix[j] - prefix[i]) - dp[i+1][j], prefix[j-1] - dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
// // 0 -> alice , 1-> bob
// int rec(vi &v,int turn,int i,int j){
//     if(i==j){
//         return 0;
//     }
//     int ans=0;
//     if(!turn){
//         ans= v[i] + rec(v,turn^1,i+1,j);
//         ans= min(ans,v[j] + rec(v,))
//     }
// }

int main()
{

    return 0;
}