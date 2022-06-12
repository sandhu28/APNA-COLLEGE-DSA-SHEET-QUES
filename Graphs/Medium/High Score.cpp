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
        v[i] = {x, y, -1 * w};
    }
    vlli dis(n + 1, INF);
    // vi par(n+1,-1);
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &edge : v)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            // par[b]=a;
            if (dis[a] == INF)
            {
                continue;
            }
            if (dis[a] + 1LL * w < dis[b])
            {
                dis[b] = dis[a] + 1LL * w;
            }
        }
    }
    lli ans = (-1) * dis[n];
    // rep(i, 0, n+1)
    // {
    //     z(i);
    //     c(dis[i]);
    // }
    bool f = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &edge : v)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            if(dis[a]== INF){
                continue;
            }
            if (dis[a] == -INF)
            {
                dis[b] = -INF;
                continue;
            }
            if (dis[a] + 1LL * w < dis[b])
            {
                dis[b] = -1 * INF;
                f = 1;
            }
        }
    }
    if (f)
    {
        if (dis[n] == -INF)
        {
            c("-1");
        }
        else
        {
            c(ans);
        }
    }
    else
    {
        c(ans);
    }
    // rep(i, 0, n + 1)
    // {
    //     z(i);
    //     if (dis[i] == -INF)
    //     {
    //         c("-INF");
    //     }
    //     else
    //     {
    //         c(dis[i]);
    //     }
    // }

    return 0;
}