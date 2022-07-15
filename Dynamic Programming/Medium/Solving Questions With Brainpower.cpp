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

long long mostPoints(vector<vector<int>>& q) {
    int n= q.size();
    vlli dp(n,0);
    dp[n-1]= q[n-1][0];
    for(int i=n-2;i>=0;i--){
        lli solve= q[i][0];
        solve+= (i+q[i][1]+1)<n? dp[i+q[i][1] +1]:0;
        lli notSolve= dp[i+1];
        dp[i]= max(solve,notSolve);
    }
    return dp[0];

}

int main(){
    
    return 0;
}