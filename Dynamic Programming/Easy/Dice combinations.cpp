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
const int M= 1e9 + 7;
const int N= 1e6 + 2;
int memo[N];

// int dp(int n){
//     if(n==0){
//         return 1;
//     }
//     if(memo[N]!=0){
//         return memo[n];
//     }
//     int ans=0;
//     for(int i=1;i<=6;i++){
//         if(i<=n){
//             ans+= dp(n-i);
//         }
//     }
//     return memo[n] = ans;
// }

int dp_table(int n){
    vi dp(n+1,0);
    dp[0] =1;
    for(int i=1;i<=n;i++){
        for(int j= 1;j<=6;j++){
            if(j<=i){
                dp[i] = ((dp[i%M]) + (dp[i-j]%M))%M;
            }
        }
    }
    return dp[n];
}

int main(){
    int n;cin>>n;

    c(dp_table(n));
    
    return 0;
}