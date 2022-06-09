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

int bfs(vi g[],int n,vi &lev,vi&p){
    queue<int> q;
    q.push(1);
    lev[1]=0;
    while(!q.empty()){
        int curr= q.front();
        q.pop();
        for(auto &child:g[curr]){
            if(lev[curr] + 1< lev[child]){
                lev[child] = lev[curr] + 1;
                p[child]= curr;
                q.push(child);
            }
        }
    }
    return lev[n];
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
    vi lev(n+1,INF);
    vi p(n+1,-1);
    int ans= bfs(g,n,lev,p);
    if(ans==INF){
        c("IMPOSSIBLE");
        return 0;
    }
    c(ans +1);
    int i= n;
    vector<int> vec;
    while(i!=1){
        vec.push_back(i);
        i= p[i];
    }
    vec.push_back(1);
    reverse(vec.begin(),vec.end());
    for(auto &e: vec){
        z(e);
    }
    return 0;
}