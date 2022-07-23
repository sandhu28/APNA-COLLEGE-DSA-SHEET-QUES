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

int recur(vi &v,int buy, int n,int i,vector<vvi> &dp,int cap){
    if(cap==0){return 0;}
    if(i==n){
        return 0;
    }
    if(dp[i][buy][cap]!=-1){
        return dp[i][buy][cap];
    }
    if(buy){
        return dp[i][buy][cap]= max(-v[i]+recur(v,0,n,i+1,dp,cap),recur(v,1,n,i+1,dp,cap));
    }
    return dp[i][buy][cap] = max(v[i]+recur(v,1,n,i+1,dp,cap-1),recur(v,0,n,i+1,dp,cap));
}

int dpTable(vi &v){
    int n= v.size();
    vector<vvi> dp(n+1,vvi(2,vi(3,0)));
    
    for(int i=n-1;i>=0;i--){
        for(int buy= 0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[i][buy][cap]=max(-v[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                }
                else{
                    dp[i][buy][cap]= max(v[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

int dpTable2(vi &v){
    int n= v.size();
    vvi after(2,vi(3,0));
    vvi curr(2,vi(3,0));
    
    for(int i=n-1;i>=0;i--){
        for(int buy= 0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    curr[buy][cap]=max(-v[i]+after[0][cap],after[1][cap]);
                }
                else{
                    curr[buy][cap]= max(v[i]+ after[1][cap-1],after[0][cap]);
                }
            }
        }
        after= curr;
    }
    return after[1][2];
}

int maxProfit(vector<int>& v) {
    int n= v.size();
    int buy= 1;
    int cap=2;
    vector<vvi> dp(n,vvi(2,vi(3,-1)));
    return recur(v,buy,n,0,dp,cap);
}

int main(){
    
    return 0;
}