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
const int N = 502;

lli dpTable(int k,int n,vi &v){
   vector<vlli> dp(n+1,vlli(k+1,0));
   for(int i=0;i<=n;i++){
    dp[i][0] = 1;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
        lli ans= 0;
        ans += dp[i-1][j];
        if(v[i-1]<= j){
            ans+= dp[i-1][j-v[i-1]];
        }
        dp[i][j]= ans%M;
    }
   }
   return dp[n][k];
}

int main(){

    int n;cin>>n;
    int sm = (n*(n+1))/2;
    if(sm&1){
        c('0');
    }
    else{
        int k= sm>>1;
        vi v(n-1);
        for(int i=0;i<n-1;i++){
            v[i]= i+1;
        }
        c((dpTable(k,n-1,v)));

    }
    
    return 0;
}