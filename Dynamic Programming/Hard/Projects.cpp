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
const int N = 1e5+ 3;

// int dpRecur(int n,int i,vvi &v,int en){
//     if(i==n-1){
//         if(v[i][0]>en){
//             return v[i][2];
//         }
//         return 0;
//     }
//     int curr= dpRecur(n,i+1,v,en);
//     if(v[i][0]>en){
//         curr= max(curr, v[i][2] + dpRecur(n,i+1,v,v[i][1]));
//     }
//     return curr;
// }

lli dpTable(int n,vector<pair<pii,int>> &v,vi &st){
    lli dp[n+1];
    dp[n]=0;
    dp[n-1] = v[n-1].second;
    for(int i=n-2;i>=0;i--){
        dp[i] = dp[i+1];
        int en= v[i].first.second;
        auto it= upper_bound(st.begin(),st.end(),en);
        // if(it==st.end()){dp[i] = max(dp[i],v[i][2]*1LL);continue;}
        int idx = it- st.begin();
        lli k=  dp[idx] + (long long)(v[i].second);
        dp[i] = max(dp[i],k);
    }
    return dp[0];
}

int main(){
    int n;cin>>n;
    vector<pair<pii,int>> v;
    vi st;
    rep(i,0,n){
        int x,y,price;
        cin>>x>>y>>price;
        v.push_back({{x,y},price});
        st.push_back(x);
    }
    sort(v.begin(),v.end());
    sort(st.begin(),st.end());
    lli ans= dpTable(n,v,st);
    c(ans);
    
    return 0;
}