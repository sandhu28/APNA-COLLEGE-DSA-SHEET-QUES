#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
// #define int long long int
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
const int N = 1e6+ 2;
lli dp[N][2];
int main(){
    fast_io;
    int t=1;
    while(t--){
        int n= 1e6;
        // c(n);
        // lli dp[n+2][2];
        dp[n+1][0]=1; dp[n+1][1]= 1;
        // c(dp[n+1][0]);
        for(int i=n;i>=2;i--){
            lli way1 = (dp[i+1][0] + dp[i+1][1])%M;
            lli way2 = (dp[i+1][0])%M;
            lli way3 =  (2*1LL*dp[i+1][0]) %M;
            lli way4 = (dp[i+1][1])%M ;
            dp[i][0]= (way1 + way2 + way3)%M ;

            dp[i][1] = (way1 + way4)%M;
        }
        // c("yes");
        // c((dp[2][0] + dp[2][1])%M);
    }
    int q;cin>>q;
    while(q--){
        int query;cin>>query;
        cout << (1LL*dp[1000000 - query + 2][1] + 1LL*dp[1000000 - query + 2][0])%M<<endl;
    }

    
    return 0;
}