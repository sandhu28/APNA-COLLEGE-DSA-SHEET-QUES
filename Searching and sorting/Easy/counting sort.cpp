#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

vi ctSort(vi& v){
    int n= v.size();
    vi ans(n,0);
    int mn = *min_element(v.begin(),v.end());
    int mx= *max_element(v.begin(),v.end());
    c(mn);c(mx);
    int range= mx-mn+1;
    vi count(range,0);
    for(int i=0;i<n;i++){
        count[v[i] - mn]++;
    }
    for(int i=1;i<n;i++){
        count[i]+= count[i-1];
    }
    
    for(int i=n-1;i>=0;i--){
        ans[--count[v[i]-mn]]= v[i];
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    vi ans= ctSort(v);
    cout<<ans.size()<<" sz";
    for(auto &e: ans){
        z(e);
    }
    return 0;
}