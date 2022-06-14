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

// Tried using djikstra but gave TLE on one test case
// void djikstra(vector<vpii> &g, int n,vi &dis,vi &par){
//     set<pii> s;
//     s.insert({0,1});
//     dis[1] =0;
//     while(!s.empty()){
//         auto pr= *s.begin();
//         s.erase(s.begin());
//         if(dis[pr.second] < pr.first){
//             continue;
//         }
//         for(auto &child: g[pr.second]){
//             if(pr.first + child.second < dis[child.first]){
//                 dis[child.first] = pr.first + child.second;
//                 par[child.first] = pr.second;
//                 s.insert({dis[child.first],child.first});
//             }
//         }
//     }
    
// }

void visit(vvi &g, int ver,vi& dp,vi &par, vi &vis){
    vis[ver] =1 ;
    dp[ver] =0;
    for(auto &child: g[ver]){
        if(!vis[child]){
            visit(g,child,dp,par,vis);
        }
        if(dp[child] + 1> dp[ver]){
            par[child] = ver;
            dp[ver] = dp[child] + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vi> v(n+1);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
    }
    vi dp(n+1,0);
    vi par(n+1,-1);
    vi vis(n+1,0);
    visit(v,1,dp,par, vis);
    if(dp[1]==0){
        c("IMPOSSIBLE");
    }
    else{
        c((dp[1]) + 1);
        vi ans;
        int i= n;
        while(i != -1){
            ans.push_back(i);
            i= par[i];
        }
        // ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for(auto &e:ans){
            z(e);
        }

    }





    // djikstra(v,n,dist,par);
    // if(dist[n]== INF){
    //     c("IMPOSSIBLE");
    // }
    // else{
    //     c((-1 * dist[n]) + 1);
    //     vi ans;
    //     int i= n;
    //     while(i != -1){
    //         ans.push_back(i);
    //         i= par[i];
    //     }
    //     // ans.push_back(1);
    //     reverse(ans.begin(),ans.end());
    //     for(auto &e:ans){
    //         z(e);
    //     }

    // }


    
    return 0;
}