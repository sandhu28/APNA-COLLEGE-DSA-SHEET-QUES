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

const int M = 1e9 + 7;
const int N = 1e6+ 2;
int dp[N];

int dp_tab(int k){
    // for(int i=1;i<=k;i++){
    //     dp[i]=0;
    // }
    // dp[0] = 1;
    for(int i=1;i<=k;i++){
        int temp= i;
        int ans=INT_MAX;
        while(temp!=0){
            int digit= temp%10;
            temp= temp/10;
            if(digit==0){continue;}
            if(digit<= i){
                ans= min(ans,1+ dp[i- digit]);
            }
        }
        dp[i] = ans;
        // cout<<i<<" "<<ans<<endl;
    }
    return dp[k];  
}

int main(){
    int n;
    cin>>n;
    // vi v(n);
    // rep(i,0,n){
    //     int x;cin>>x;
    //     v[i]= (x);
    // }
    c(dp_tab(n));
    return 0;
}