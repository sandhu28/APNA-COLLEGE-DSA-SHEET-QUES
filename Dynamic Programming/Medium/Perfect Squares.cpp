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

int dp_table(int ts,vi &v,int n){
    vvi dp(n+1,vi(ts+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=ts;j++){
            if(j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j] = 1e9;
            }
            else{
                dp[i][j]=dp[i-1][j];
                if(j>=v[i-1]){
                    dp[i][j]= min(dp[i][j],1+dp[i][j-v[i-1]]);
                }
            }
        }
    }
    return dp[n][ts];
}
int numSquares(int n) {
    vi v;
    for(int i=1;i<102;i++){
        if(i*i<= n){
            v.push_back(i);
        }
    }
    return dp_table(n,v,v.size());

}

int main(){
    
    return 0;
}