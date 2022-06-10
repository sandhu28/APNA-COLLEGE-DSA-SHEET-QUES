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

void djikstra(vector<vpii> v,int n,vlli &dis,vi &vis){
    set<pair<lli,int>> s;// dist, vertex
    s.insert({0,1});
    dis[1] =0;
    while(!s.empty()){
        auto pr= *s.begin();
        s.erase(s.begin());
        int currVer= pr.second;
        if(vis[currVer]==1){continue;}
        for(auto &child: v[currVer]){
            int childVer= child.first;
            int w = child.second;
            if(dis[currVer] + 1LL*w < dis[childVer]){
                dis[childVer] = dis[currVer] + 1LL*w;
                s.insert({dis[childVer],childVer});
            }
        }
        vis[currVer] =1;
    }
}

int main(){
    int n,m;cin>>n>>m;
    vlli dis(n+1,LLONG_MAX);
    vi vis(n+1, 0);
    vector<vpii> v(n+1);
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        v[x].push_back({y,w});
        // v[y].push_back({x,w});
    }
    djikstra(v,n,dis,vis);
    for(int i=1;i<=n;i++){
        z(dis[i]);
    }
    
    return 0;
}