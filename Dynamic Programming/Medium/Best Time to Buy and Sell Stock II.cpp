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
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int recur(vi &v,int buy, int n,int i,vvi &dp){
    if(i==n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
        return dp[i][buy]= max(-v[i]+recur(v,0,n,i+1,dp),recur(v,1,n,i+1,dp));
    }
    return dp[i][buy]= max(v[i]+recur(v,1,n,i+1,dp),recur(v,0,n,i+1,dp));
}

int dpTable(vi &v){
    int n= v.size();
    vvi dp(n+1,vi(2,-1));
    dp[n][0]=dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][1]= max(-v[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0]= max(v[i]+dp[i+1][1],dp[i+1][0]);
    }
    return dp[0][1];
}

int maxProfit(vector<int>& v) {
    int n= v.size();
    bool buy= 1;
    vvi dp(n,vi(2,-1));
    return recur(v,buy,n,0,dp);
}

int main(){
    
    return 0;
}