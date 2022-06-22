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

bool bfs(vvi &g,vi &lev,vi &vis){

    queue<pii> q;
    q.push({1,0});
    vis[1]=1;
    lev[1]=0;
    while(!q.empty()){
        int ver= q.front().first;
        int curr_lev= q.front().second;
        q.pop();
        for(auto &child: g[ver]){
            if(vis[child]==1 && (lev[child]==lev[ver])){
                return 0;
            }
            else if(vis[child]==1){
                continue;
            }
            else{
                q.push({child,curr_lev^1});
                vis[child]=1;
                lev[child]= curr_lev^1;
            }
        }
    }
    return 1;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vvi g(n+1);
    for(int i=0;i<dislikes.size();i++){
        int x= dislikes[i][0],y= dislikes[i][1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vi lev(n+1,-1);
    vi vis(n+1,0);
    return bfs(g,lev,vis);

}

int main(){
    
    return 0;
}