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
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int recur(int copy, int currAs,int n,vvi &dp){
    // z(copy);c(currAs);
    if(currAs==n){
        return 0;
    }
    if(currAs>n){return -1;}
    if(dp[currAs][copy]!=-1){
        return dp[currAs][copy];
    }
    int ans= INT_MAX;
    if(copy>= currAs ){
        int temp= recur(copy,currAs+copy,n,dp);
        if(temp!=-1){
            ans= min(ans, 1 + temp);
        }
    }
    else{
        int a= recur(currAs,currAs,n,dp);
        if(a!=-1){
            ans= min(ans,1+ a);
        }
        if(copy!=0){
            int b = recur(copy,currAs+copy,n,dp);
        if(b!=-1){
            ans= min(ans,1+b);
        }
        }
    }
    return dp[currAs][copy]= ans==INT_MAX? -1: ans;

}
    
int minSteps(int n) {
    vvi dp(n,vi(n+1,-1));
    return recur(0,1,n,dp);
}

int main(){
    
    return 0;
}