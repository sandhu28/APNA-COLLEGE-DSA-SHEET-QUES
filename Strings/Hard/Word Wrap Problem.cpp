#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int sq(int a){
    return a*a;
}
int min_cost(vi& word, int n,int k,int reml, vvi &vis,int i){

    if(vis[i][reml]!=-1){
        return vis[i][reml];
    }
    if(i == n-1){
        vis[i][reml] = word[i]<reml? 0:sq(reml);
        return vis[i][reml];
    }

    if(word[i]<reml){
        return vis[i][reml] = min(min_cost(word,n,k,reml== k? reml-word[i]:reml-word[i]-1,vis,i+1),
                   (sq(reml) + min_cost(word,n,k,k-word[i],vis,i+1)));
    }
    return vis[i][reml]= sq(reml)+ min_cost(word,n,k,k-word[i],vis,i+1);
}

int min_cost_dp(vi& word, int n,int k){
    int dp[n][k+1]={};
    for(int idx= 0;idx<=k;idx++){
        if(word[n-1]>=idx){
            dp[n-1][idx] = idx*idx;
        }
        else{
            dp[n-1][idx] = 0;
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=k;j>=0;j--){
            if(word[i]<j){
                if(j==k){
                    dp[i][j]= min(dp[i+1][j-word[i]],j*j + dp[i+1][k-word[i]]);
                }
                else{
                    dp[i][j] = min(dp[i+1][j-word[i]-1], j*j + dp[i+1][k-word[i]]);
                }
            }
            else{
                dp[i][j] = j*j + dp[i+1][k-word[i]];
            }
        }
    }
    int ans= INT_MAX;
    for(int j=0;j<=k;j++){
        ans= min(ans,dp[0][j]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    vi v(n);
    rep(i,0,n){cin>>v[i];}
    vvi vis(n,vi(k+1,-1));
    // c(min_cost(v,n,k,k,vis,0));
    c(min_cost_dp(v,n,k));
    return 0;
}