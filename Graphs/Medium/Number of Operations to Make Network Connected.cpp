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
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

void dfs(vvi &g,int i,vi &vis){
    vis[i]= 1;
    for(auto &child: g[i]){
        if(!vis[child]){
            dfs(g,child,vis);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    int edges= connections.size();
    if(edges<n-1){
        return -1;
    }
    vvi g(n);
    for(int i=0;i<edges;i++){
        auto v= connections[i];
        g[v[0]].push_back(v[1]);
        g[v[1]].push_back(v[0]);
    }
    vi vis(n,0);
    int ct=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ct++;
            dfs(g,i,vis);
        }
    }
    return ct-1;

}


int main(){
    
    return 0;
}