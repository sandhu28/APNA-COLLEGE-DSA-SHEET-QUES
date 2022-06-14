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

void dfs1(vvi &g,int n,stack<int> &stk,int i,vi &vis){
    vis[i] = 1;
    for(auto &child: g[i]){
        if(!vis[child]){
            dfs1(g,n,stk,child,vis);
        }
    }
    stk.push(i);
}
void dfs(vvi &g,int i,vi &vis,int ct,vi &kingdom){
    vis[i] = 1;
    kingdom[i] = ct;
    for(auto &child: g[i]){
        if(!vis[child]){
            dfs(g,child,vis,ct,kingdom);
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    vvi g(n+1);
    vvi rev(n+1);
    vi vis(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        rev[y].push_back(x);
    }
    stack<int> stk;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(g,n,stk,i,vis);
        }
    }
    vi kingdom(n+1,0);
    int ct=0;
    for(int i=1;i<=n;i++){
        // z(vis[i]);
        vis[i]=0;
    }
    while(!stk.empty()){
        int i= stk.top();
        // z("curr_top");c(i);
        stk.pop();
        if(vis[i]==0){
            // z("dfs for ");c(i);
            ct++;
            dfs(rev,i,vis,ct,kingdom);
        }
    }
    c(ct);
    for(int i=1;i<=n;i++){
        z(kingdom[i]);
    }

    return 0;
}