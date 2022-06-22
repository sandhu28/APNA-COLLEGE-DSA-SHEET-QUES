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
#define all(x) (x).begin(), (x).end()
#define rep(i, k, n) for (int i = k; i < n; ++i)
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

vpii mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0) && (j >= 0) && i < m && (j < n);
}

int shortestPath(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    if (m == 1 && n == 1)
    {
        return 0;
    }
    vvi vis(m, vi(n, -1));
    vis[0][0] = k;
    queue<vi> q;
    q.push({0, 0, 0, k});
    while (!q.empty())
    {
        auto vec = q.front();
        int cr = vec[0], cc = vec[1];
        int cl = vec[2];
        int ck = vec[3];

        q.pop();
        for (auto &dir : mov)
        {
            int nr = vec[0] - dir.first;
            int nc = vec[1] - dir.second;
            if (!isValid(nr, nc, m, n))
            {
                continue;
            }
            if (grid[nr][nc] == 1)
            {
                if (ck <= 0)
                {
                    continue;
                }
                else
                {
                    if (vis[nr][nc] != -1 && vis[nr][nc] >= (ck - 1))
                    {
                        continue;
                    }
                    else
                    {
                        q.push({nr, nc, cl + 1, ck - 1});
                        vis[nr][nc] = ck-1;
                    }
                }
            }
            else
            {
                if (vis[nr][nc] != -1 && vis[nr][nc] >= ck)
                {
                    continue;
                }
                else
                {
                    q.push({nr, nc, cl + 1, ck});
                    vis[nr][nc] = ck;
                }
            }
            if (nr == m - 1 && nc == n - 1)
            {
                return cl + 1;
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}