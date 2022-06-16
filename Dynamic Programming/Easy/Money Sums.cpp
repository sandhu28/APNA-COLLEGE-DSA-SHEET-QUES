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

vi dpTable(int n,vi &coins){
    int m=accumulate(coins.begin(),coins.end(),0);
    vvi dp(n+1,vi(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]= dp[i-1][j];
            if(coins[i-1]<= j){
                dp[i][j] = max(dp[i][j],dp[i-1][j-coins[i-1]]);
            }
        }
    }
    // int ct=0;
    vi ans;
    for(int j=1;j<=m;j++){
        if(dp[n][j]){
            ans.push_back(j);
        }
    }
    return ans;
}

int main(){
    
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto ans= dpTable(n,v);
    c(ans.size());
    for(auto &e: ans){
        z(e);
    }


    return 0;
}