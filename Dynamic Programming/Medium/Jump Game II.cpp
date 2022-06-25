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

struct pr{
    int idx;
    int steps;
    int mnjumps;
    string psf;
};
int jump(vector<int>& nums) {
    int n= nums.size();
    vector<int> dp(n,1e9);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int mxJumps = nums[i];
        if(mxJumps==0){
            continue;
        }
        // int curr=1e9;
        for(int j= 1;(i+j<= n-1) && (j<=mxJumps) ;j++){
            dp[i]= min(dp[i],1 + dp[i+j]);
        }
    }
    c(dp[0]);
    // for(int i=0;i<n;i++){
    //     z(dp[i]);
    // }
    queue<pr> q;
    q.push({0,nums[0],dp[0],"0"});
    while(!q.empty()){
        auto pair= q.front();
        q.pop();
        if(pair.mnjumps == 0){
            cout<<pair.psf<<endl;
            continue;
        }
        for(int j=1;(pair.idx + j< n)  && j<=pair.steps; j++ ){
            if(dp[pair.idx + j] == pair.mnjumps -1){
                q.push({pair.idx + j, nums[pair.idx + j],pair.mnjumps-1,pair.psf + "->" + to_string(pair.idx + j)});;
            }
        }
    }

    return dp[0];
}

int main(){
    fast_io;
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    jump(v);
    
    return 0;
}