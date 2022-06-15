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

int dp_min(int n,int k,vi &v,int i){
    if(k==0){
        return 0;
    }
    if(i>=n){
        return 1e9;
    }
    int ans= INT_MAX;
    ans= min(ans,dp_min(n,k,v,i+1));
    if(v[i]<= k){
        ans= min(ans,1 + dp_min(n,k-v[i],v,i));
    }
    return ans;
}


int dp_tab(int n,int k,vi &v){
    vvi dp(n+1,vi(k+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j]=0;
                continue;
            }
            if(i==0){
                dp[i][j]= 1e9;
            }    
        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1]<= j){
                dp[i][j] = min(dp[i][j], 1 + dp[i][j- v[i-1]]);
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=k;j++){
    //         if(dp[i][j]>=1e9){
    //             z("INF");
    //         }
    //         else{
    //             z(dp[i][j]);
    //         }
    //     }
    //     nl;
    // }
    return dp[n][k]>= 1e9? -1:dp[n][k];

}

int main(){
    int n;int k;
    cin>>n>>k;
    vi v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int ct=0;
    // c(dp_min(n,k,v,0));
    c(dp_tab(n,k,v));
    return 0;
}