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

int maxCoins(vector<int>& nums) {
    int n= nums.size();
    vi temp(n+2);
    temp[0]= temp[n+1]= 1;
    for(int i=1;i<=n;i++){
        temp[i]= nums[i-1];
    }
    vvi dp(n,vi(n,0));
    for(int g=0;g<n;g++){
        int i=0;
        for(int j=g;j<n;j++,i++){
            if(g==0){
                dp[i][j]= temp[i]*temp[i+1]*temp[i+2];
            }
            else{
                int mn= INT_MIN;
                for(int k=i;k<=j;k++){
                    int left= k-1<0?0:dp[i][k-1];
                    int right= k+1>=n?0: dp[k+1][j];
                    int curr= temp[i]*temp[k+1]*temp[j+2];
                    int ans= left+right+curr;
                    if(ans>mn){
                        mn= ans;
                    }
                }
                dp[i][j]= mn;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         z(dp[i][j]);
    //     }
    //     nl;
    // }
    return dp[0][n-1];

}

int main(){
    fast_io;
    int n;cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    c(maxCoins(v));
    
    return 0;
}