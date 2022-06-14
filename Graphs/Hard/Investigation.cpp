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
const int M= 1e9+7;


void djikstra(vector<vpii> g,vlli &dis,vi &min_ct,vi &max_ct,vi &routes){
    set<pair<lli,int>> s;
    s.insert({0,1});
    dis[1] =0;
    min_ct[1]=0;
    max_ct[1]=0;
    routes[1] = 1;
    while(!s.empty()){
        auto pr= *s.begin();
        lli c= pr.first;int u= pr.second;
        s.erase(s.begin());
        for(auto &child: g[u]){
            int v= child.first;
            int d= child.second;
            if(c + 1LL*d> dis[v]){continue;}
            else if(c + 1LL*d == dis[v]){
                // s.insert({dis[v],v});
                routes[v] += routes[u];
				routes[v] %= M;
                min_ct[v] = min(min_ct[v],1+min_ct[u]);
                max_ct[v]= max(max_ct[v], 1 + max_ct[u]);
            }
            else{
                dis[v] = c + 1LL*d;
                s.insert({dis[v],v});
                routes[v] = routes[u];
                min_ct[v] = (1+min_ct[u]);
                max_ct[v]= (1 + max_ct[u]);
            }
        }
    }
}


int main(){

    int n,m;cin>>n>>m;
    vector<vpii> g(n+1);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    int ct=0;
    vlli dis(n+1,1e17);
    vi min_ct(n+1,0);
    vi max_ct(n+1,0);
    vi routes(n+1,0);
    djikstra(g,dis,min_ct,max_ct,routes);
    z(dis[n]);
    z(routes[n]);
    z(min_ct[n]);
    z(max_ct[n]);

    
    return 0;
}