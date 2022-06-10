#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

int dfs(vi g[], int n, vi &vis, vi &par, int i)
{
    // c(i);
    // cout<<i<<" -> ";
    // for (int i = 0; i <= n; i++)
    // {
    //     z(par[i]);
    // }
    // nl;
    vis[i] = 1;
    for (auto &child : g[i])
    {
        if ((vis[child] == 1) && (child != par[i]))
        {
            par[child]=i;
            return child;
        }
        if (vis[child] == 1)
        {
            continue;
        }
        par[child] = i;
        auto ans = dfs(g, n, vis, par, child);
        if (ans != -1)
        {
            return ans;
        };
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vi g[n + 1];
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vi par(n + 1, -1);
    vi vis(n + 1, 0);
    int node=INT_MIN;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            node= dfs(g, n,vis,par, i);
            if(node!=-1){
                break;
            }
        }
    }
    // c(node);
    if (node == -1)
    {
        c("IMPOSSIBLE");
        return 0;
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     z(par[i]);
    // }
    vector<int> ans;
    ans.push_back(node);
    int i= par[node];
    while(i!= node){
        ans.push_back(i);
        i= par[i];
    }
    ans.push_back(i);
    reverse(ans.begin(),ans.end());
    c(ans.size());
    for(auto &e: ans){
        z(e);
    }
    return 0;
}