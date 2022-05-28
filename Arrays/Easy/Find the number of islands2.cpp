#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis, int n, int m)
{
    if (grid[i][j] == '1')
    {
        vis[i][j] = 1;
        for (auto &pr : dir)
        {
            int nr = i - pr.first;
            int nc = j - pr.second;
            if ((nr< 0 || nr >= n || nc< 0 || nc >= m) && (vis[nr][nc]==1))
            {
                continue;
            }
            dfs(grid, nr, nc, vis, n, m);
        }
    }
    return;
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((grid[i][j] == '1') || (vis[i][j] == 0))
            {
                dfs(grid, i, j, vis, n, m);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}