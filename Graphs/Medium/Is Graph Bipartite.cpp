#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int bfs(vvi &g,vi &lev,vi &vis,int n){
    queue<int> q;
    q.push(0);
    vis[0]=1;
    lev[0]=0;

    while(!q.empty()){
        int cN= q.front();
        int cL= lev[cN];
        q.pop();
        for(auto &child: g[cN]){
            if((vis[child]==1) && lev[child]== cL){
                return 0;
            }
            if(vis[child]==1){continue;}
            lev[child]= cL^1;
            vis[child]=1;
            q.push(child);
        }
    }
    return 1;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n= graph.size();
    vvi g(n);
    fo(i,n){
        int m= graph[i].size();
        fo(j,m){
            g[i].push_back(graph[i][j]);
        }
    }
    vi lev(n,INF);
    vi vis(n,0);

    return bfs(g,lev,vis,n);
}

int main(){
    
    return 0;
}