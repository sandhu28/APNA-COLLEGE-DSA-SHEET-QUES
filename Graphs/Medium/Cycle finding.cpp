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
#define INF LONG_MAX
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vvi v(m);
    rep(i, 0, m)
    {
        int x, y, w;
        cin >> x >> y >> w;
        v[i] = {x, y, w};
    }
    for(int i=1;i<=n;i++){
        v.push_back({0,i,0});
    }
    vlli dis(n + 1, 0);
    vi par(n+1,0);
    // dis[1] = 0;
    int x ;
    for (int i = 1; i <= n; i++)
    {
        x= -1;
        for (auto &edge : v)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            if (dis[a] + 1LL * w < dis[b])
            {
                par[b]=a;
                dis[b] = dis[a] + 1LL * w;
                x= b;
            }
        }
    }
    if(x==-1){
        c("NO");
    }
    else{
        c("YES");
        for(int i=1;i<=n;i++){
            x= par[x];
        }
        vi ans;
        ans.push_back(x);
        int temp=par[x];
        while(temp!= x){
            ans.push_back(temp);
            temp= par[temp];
        }
        ans.push_back(x);
        reverse(ans.begin(),ans.end());
        for(auto &e: ans){
            z(e);
        }
    }
    return 0;
}