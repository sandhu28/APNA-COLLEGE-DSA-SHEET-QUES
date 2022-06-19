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

lli dpTable(int n,vi &coins){
    vector<vlli> dp(n,vlli(n,-1));
    for(int g=0;g<n;g++){
        int i=0;
        for(int j=g;j<n;j++){
            if(g==0){
                dp[i][j] = coins[i];
            }
            else if(g==1){
                dp[i][j] = max(coins[i],coins[j]);
            }
            else{
                dp[i][j] = max((coins[i]*1LL + min(dp[i+2][j],dp[i+1][j-1])),
                               coins[j]*1LL + min(dp[i+1][j-1],dp[i][j-2]));
            }
            i++;
        }
    }
    // rep(i,0,n){
    //     rep(j,0,n){
    //         z(dp[i][j]);
    //     }
    //     nl;
    // }
    return dp[0][n-1];
}

int main(){

    int n;cin>>n;
    vi coins;
    rep(i,0,n){
        int x;cin>>x;
        coins.push_back(x);
    }
    // c(n);
    // for(auto &e:coins){
    //     z(e);
    // }
    c(dpTable(n,coins));
    return 0;
}