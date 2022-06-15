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
int dp[1002][N];

int dp_tab(int n,int w,vi &price,vi &pages){
    for(int i=1;i<=n;i++){
        for(int j= 1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j>= price[i-1]){
                dp[i][j] = max(dp[i][j],pages[i-1] + dp[i-1][j-price[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int main(){

    int n,w;
    cin>>n>>w;
    vi price(n);
    vi pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    c(dp_tab(n,w,price,pages));
    return 0;
}