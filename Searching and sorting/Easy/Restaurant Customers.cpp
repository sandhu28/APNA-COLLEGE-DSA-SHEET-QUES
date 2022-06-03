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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int st,en;cin>>st>>en;
        v.push_back({st,1});
        v.push_back({en,-1});
    }
    sort(v.begin(),v.end());
    int mx=0;int ct=0;
    for(auto &pr: v){
        ct+= pr.second;
        mx= max(mx,ct);
    }
    cout<<mx<<endl;
    return 0;
}