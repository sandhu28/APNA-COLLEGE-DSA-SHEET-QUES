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

// int BFS(vector<vpii> &g,vi &lev,int i){
//     queue<pii> q;
//     q.push({i,0});
//     lev[i]=0;
//     int ans=0;
//     while(!q.empty()){
//         auto pr= q.front();
//         int cn= pr.first;
//         int cl= pr.second;
//         for(auto &child: g[cn]){
//             int childNode= child.first;
//             int w= child.second;
//             if(lev[childNode]> lev[cn] + w){
//                 lev[childNode] = lev[cn] + w;
//                 ans= max(ans,lev[childNode]);
//                 q.push({childNode,lev[childNode]});
//             }
//         }
//     }
//     return ans;
// }

int dfs(vector<vpii> &g,int i){

    int ans= 0;
    for(auto &child: g[i]){
        ans= max(ans,child.second + dfs(g,child.first));
    }
    return ans;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

    vector<vpii> g(n);
    for(int i=0;i<n;i++){
        if(manager[i]==-1) continue;
        g[manager[i]].push_back({i,informTime[manager[i]]});
    }
    vi vis(n,0);
    return dfs(g,headID);

        
}

int main(){
    
    return 0;
}