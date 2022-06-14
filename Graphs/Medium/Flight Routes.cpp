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

vlli djikstra_modified(vector<vpii> &v,int n,int k,vector<vlli> &dis){
    multiset<pair<lli,int>> s;
    s.insert({0,1});
    // for(int j=0;j<k;j++){
    //     dis[1][j]=0;
    // }
    dis[1][0] = 0;
    while(!s.empty()){
        auto pr= *s.begin(); 
        s.erase(s.begin());
        int currVer= pr.second;
        lli currCost= pr.first;
        // z(currCost); c(currVer);
        if(dis[currVer][k-1]< currCost){
            continue;
        }
        for(auto &child: v[currVer]){
            int childVer = child.first;
            int w = child.second;
            if((currCost + 1LL*w) < dis[childVer][k-1]){
                dis[childVer][k-1] = currCost + 1LL*w;
                s.insert({dis[childVer][k-1],childVer});
                sort(dis[childVer].begin(),dis[childVer].end());
            }
        }
    }
    return dis[n];

}

int32_t main(){
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vpii> v(n+1);
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back({y,w});
    }
    vector<vlli> dis(n+1,vlli(k,1e16));
    auto ans= djikstra_modified(v,n,k,dis);
    for(auto &e: ans){
        z(e);
    }
    // c("d");
    // for(int i=0;i<=n;i++){
    //     for(auto e: dis[i]){
    //         z(e);
    //     }
    //     nl;
    // }
 
    return 0;
}