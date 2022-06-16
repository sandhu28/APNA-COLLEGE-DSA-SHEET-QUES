#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int dpTable(int n,int m){
    vvi dp(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                int ans= INT_MAX;
                for(int col= 1;col<j;col++){
                    ans= min(ans,1+ dp[i][j-col] + dp[i][col]);
                }
                for(int row= 1;row<i;row++){
                    ans= min(ans,1 + dp[row][j] + dp[i-row][j]);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[n][m];
}
int main(){
    int n,m;
    cin>>n>>m;
    c(dpTable(n,m));
    return 0;
}