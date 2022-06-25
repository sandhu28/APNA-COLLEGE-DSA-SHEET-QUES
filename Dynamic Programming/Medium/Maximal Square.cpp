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

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(),n= matrix[0].size();
    vvi dp(m,vi(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='0'){
                dp[i][j]=0;
            }
            else{
                if(i==m-1 || j== n-1){
                    dp[i][j] = 1;
                }
            }
        }
    }
    int mx=INT_MIN;
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j] = 1 +min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
            mx= max(mx,dp[i][j]);
        }
    }
    return mx;
}

int main(){
    
    return 0;
}