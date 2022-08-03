#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

// vpii mov= {{1,0},{-1,0},{0,1},{0,-1}};

// bool isValid(int i,int j,int m,int n){
//     return (i>=0) && (j>=0 )&& (i<m) && (j<n);
// }

// int bfs(vvi &grid,vvi &lev, vvi &vis,int m,int n){
//     queue<pii> q;
//     fo(i,m){
//         fo(j,n){
//             if(grid[i][j]==2){
//                 vis[i][j]=1;
//                 q.push({i,j});
//                 lev[i][j]=0;
//             }
//             else if(grid[i][j]==0){
//                 lev[i][j]=0;
//                 vis[i][j]=1;
//             }
//             else{
//                 continue;
//             }
//         }
//     }
//     int ans= INT_MIN;
//     while(!q.empty()){
//         int ci= q.front().first;
//         int cj= q.front().second;
//         q.pop();
//         for(auto &pr: mov){
//             int ni= ci- pr.first;
//             int nj= cj- pr.second;
//             if(!isValid(ni,nj,m,n)){continue;}
//             if(vis[ni][nj]){continue;}
//             lev[ni][nj]= lev[ci][cj]+1;
//             vis[ni][nj]=1;
//             q.push({ni,nj});
//             ans= max(ans,lev[ni][nj]);
//         }
//     }
//     fo(i,m){
//         fo(j,n){
//             if(lev[i][j]==INF){
//                 ans= -1;
//             }
//         }
//     }
//     return ans;
// }

vpii mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0) && (j >= 0) && (i < m) && (j < n);
}

int bfs(vvi &grid, vvi &lev, int m, int n)
{
    queue<pii> q;
    fo(i, m)
    {
        fo(j, n)
        {
            if (grid[i][j] == 2)
            {
                // vis[i][j]=1;
                q.push({i, j});
                lev[i][j] = 0;
            }
            else if (grid[i][j] == 0)
            {
                lev[i][j] = 0;
                // vis[i][j]=1;
            }
            else
            {
                continue;
            }
        }
    }
    int ans = INT_MIN;
    while (!q.empty())
    {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();
        for (auto &pr : mov)
        {
            int ni = ci - pr.first;
            int nj = cj - pr.second;
            if (!isValid(ni, nj, m, n))
            {
                continue;
            }
            if (lev[ci][cj] + 1 < lev[ni][nj])
            {
                lev[ni][nj] = lev[ci][cj] + 1;
                q.push({ni, nj});
                ans = max(ans, lev[ni][nj]);
            }
        }
    }
    fo(i, m)
    {
        fo(j, n)
        {
            if (lev[i][j] == INF)
            {
                ans = -1;
            }
        }
    }
    return ans==INT_MIN? 0: ans;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vvi lev(m, vi(n, INF));
    // vvi vis(m,vi(n,0));

    return bfs(grid, lev, m, n);
}

int main()
{

    return 0;
}