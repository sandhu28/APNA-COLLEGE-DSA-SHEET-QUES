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

int minimumDeleteSum(string s1, string s2){
    int n= s1.size();int m= s2.size();
    vvi dp(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        dp[i][0] += (dp[i-1][0] + (int)(s1[i-1]));
    }
    for(int j=1;j<=m;j++){
        dp[0][j] += (dp[0][j-1] + (int)(s2[j-1]));
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]== s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    
    return 0;
}