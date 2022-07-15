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

int countSquares(vector<vector<int>>& v) {
    int n= v.size();
    int m= v[0].size();
    vvi dp(n,vi(m,0));
    int ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 || j==m-1){
                if(v[i][j]==1){
                    dp[i][j]=1;
                    ans+=1;
                }
            }
            else{
                dp[i][j]=1+ min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                ans+= dp[i][j];
            }
        }
    }
    return ans;
}

int main(){
    
    return 0;
}