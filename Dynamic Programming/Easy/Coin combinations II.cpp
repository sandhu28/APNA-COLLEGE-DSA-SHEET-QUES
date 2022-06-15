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
const int N = 1e6+ 2;
int dp[101][N];

int dp_tab(int n,int k,vi &v){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j]=1;
                continue;
            }
            if(i==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            lli ans= 0;
            ans+= dp[i-1][j];
            if(j>= v[i-1]){
                ans+= dp[i][j- v[i-1]];

            }
            dp[i][j] = (ans%M);
        
        }
    }
    return dp[n][k];  
}

int main(){
    int n,k;
    cin>>n>>k;
    vi v(n);
    rep(i,0,n){
        int x;cin>>x;
        v[i]= (x);
    }
    c(dp_tab(n,k,v));
    return 0;
}