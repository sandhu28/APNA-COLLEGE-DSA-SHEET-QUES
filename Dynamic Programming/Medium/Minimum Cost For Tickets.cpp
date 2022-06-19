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

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n= days.size();
    vector<bool> travel(366,0);
    for(int i=0;i<n;i++){
        travel[days[i]]=1;
    }
    vi dp(366,0);
    dp[days[n-1]] = min(costs[0],min(costs[1],costs[2]));
    for(int i=days[n-1]-1;i>=1;i--){
        if(!travel[i]){
            dp[i]= dp[i+1];
        }
        else{
            dp[i]= min(costs[0] + dp[i+1],min(costs[1]+dp[i+6],costs[2] + dp[i+29]));
        }
    }
    return dp[1];
}

int main(){
    
    return 0;
}