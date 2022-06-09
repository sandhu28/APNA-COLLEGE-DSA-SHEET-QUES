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

int bfs(vi g[],int n,vi &vis,vi &level,int st){
    queue<pii> q;
    q.push({st,0});
    vis[st]=1;
    while(!q.empty()){
        pii pr = q.front();
        int cN= pr.first,cL= pr.second;
        level[cN] = cL + 1;
        q.pop();
        for(auto &child:g[cN]){
            int childNode= child;
            int childLevel = (cL ^ 1);
            if((vis[childNode]==1) && (level[childNode] == level[cN])){
                return -1;
            }
            else if(vis[childNode]){continue;}
            else{
                level[childNode] = childLevel + 1;
                q.push({childNode,childLevel});
                vis[childNode] =1;
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vi g[n+1];
    rep(i,0,m){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vi vis(n+1,0);
    vi lev(n+1,INF);
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        int ans= bfs(g,n,vis,lev,i);
        if(ans==-1){
            c("IMPOSSIBLE");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(lev[i]==INF){
            c("IMPOSSIBLE");
            return 0;
        }
        else{
            z(lev[i]);
        }
    }
    

    return 0;
}