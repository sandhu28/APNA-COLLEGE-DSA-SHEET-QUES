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
        int x,y;cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),[](pii & pr1, pii &pr2){
        return pr1.second< pr2.second;
    });
    int ct=0;
    int mx=INT_MIN;
    int prev=-1;
    for(int i=0;i<n;i++){
        if(v[i].first>=prev){
            ct++;
            prev= v[i].second;
        }
        mx= max(ct,mx);
    }
    cout<<mx<<endl;
    return 0;
}