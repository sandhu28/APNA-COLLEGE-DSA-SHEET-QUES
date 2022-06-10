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

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vlli> dis(n + 1, vlli(n + 1, LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        dis[x][x]= dis[y][y]=0;
        cin >> x >> y >> w;
        if(w<dis[x][y]){
            dis[x][y] = w;
            dis[y][x] = w;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                lli p= dis[i][k] + dis[k][j];
                if(p<0){p= LLONG_MAX;}
                dis[i][j] = min(dis[i][j], p);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(dis[x][y]==LLONG_MAX){
            c("-1");
        }
        else{
            c(dis[x][y]);
        }
    }

    return 0;
}