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

// bool dfs(vvi &g,int i,vector<bool> &isPresent, vi &vis,stack<int> &stk){
//     // z("yes");c(i);
//     stk.push(i);
//     vis[i]=1;
//     isPresent[i] = 1;
//     for(auto &child: g[i]){
//         if(!vis[child]){
//             if(dfs(g,child,isPresent,vis,stk)){
//                 return true;
//             }
//         }
//         if(isPresent[child]){
//             stk.push(child);
//             return true;
//         }
//     }
//     stk.pop();
//     isPresent[i] = 0;
//     return false;
// }

// void dfs2(vvi &g,int i, vi &vis,stack<int> &stk){
//     // z("yes");c(i);
//     vis[i]=1;
//     for(auto &child: g[i]){
//         if(!vis[child]){
//             dfs2(g,child,vis,stk);
//         }
//     }
//     stk.push(i);
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m;
//     cin >> n >> m;
//     vvi g(n+1);
//     rep(i, 0, m)
//     {
//         int x, y;
//         cin >> x >> y;
//         g[x].push_back(y);
//     }
//     vector<bool> isPresent(n + 1, 0);
//     vi vis(n + 1, 0);
//     stack<int> stk;
//     bool ans= 0;
//     for(int i=1;i<=n;i++){
//         if(!vis[i]){
//             ans |= dfs(g,i,isPresent,vis,stk);
//         }
//         if(ans){
//             break;
//         }
//     }
//     if(ans){
//         c("IMPOSSIBLE");
//         return 0;
//     }
//     for(int i=0;i<=n;i++){vis[i]=0;}
//     while(!stk.empty()){stk.pop();}
//     for(int i=1;i<=n;i++){
//         if(!vis[i]){
//             dfs2(g,i,vis,stk);
//         }
//     }
//     while(!stk.empty()){
//         z(stk.top());
//         stk.pop();
//     }

//     return 0;
// }


// Method 2 do not need to check for cycle first.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vvi g(n+1);
    vi inDegree(n+1,0);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        inDegree[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vi ans;
    while(!q.empty()){
        int ver= q.front();
        ans.push_back(ver);
        q.pop();
        for(auto &child: g[ver]){
            --inDegree[child];
            if(inDegree[child]==0){
                q.push(child);
            }
        }
    }
    if(ans.size()==n){
        for(auto &e: ans){
            z(e);
        }
    }
    else{
        c("IMPOSSIBLE");
    }

    return 0;
}