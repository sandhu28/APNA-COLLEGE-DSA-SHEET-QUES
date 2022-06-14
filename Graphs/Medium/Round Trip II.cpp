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

bool dfs(vvi &g,int i,vector<bool> &isPresent, vi &vis,stack<int> &stk){
    // z("yes");c(i);
    stk.push(i);
    vis[i]=1;
    isPresent[i] = 1;
    for(auto &child: g[i]){
        if(!vis[child]){
            if(dfs(g,child,isPresent,vis,stk)){
                return true;
            }
        }
        if(isPresent[child]){
            stk.push(child);
            return true;
        }
    }
    stk.pop();
    isPresent[i] = 0;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi g(n+1);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    vector<bool> isPresent(n + 1, 0);
    vi vis(n + 1, 0);
    stack<int> stk;
    bool ans= 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans |= dfs(g,i,isPresent,vis,stk);
        }
        if(ans){
            break;
        }
    }
    vi path;
    if(ans){
        int temp= stk.top();
        path.push_back(temp);
        stk.pop();
        while(!stk.empty() && (stk.top()!=temp)){
            path.push_back(stk.top());
            stk.pop();
        }
        path.push_back(temp);
        reverse(path.begin(),path.end());
        c(path.size());
        for(auto &e: path){
            z(e);
        }
    }
    else{
        c("IMPOSSIBLE");
    }
    return 0;
}