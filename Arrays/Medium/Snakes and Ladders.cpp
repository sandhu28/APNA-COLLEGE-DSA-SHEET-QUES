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

int bfs(vi &v, vi &lev, int k)
{
    queue<pii> q; // 0 matlab no snake or ladder
    q.push({1, 0});
    lev[1] = 0;
    while (!q.empty())
    {
        int cn = q.front().first;
        int temp = q.front().second;
        q.pop();
        if (temp == 0)
        {
            if (v[cn] != -1)
            {
                if (lev[v[cn]] < lev[cn] + 1)
                {
                    lev[v[cn]] = lev[cn] + 1;
                    q.push({v[cn], 1});
                    continue;
                }
            }
            for (int a = 1; a <= 6; a++)
            {
                int new_n = a + cn;
                if (new_n <= k && (lev[new_n] < lev[cn] + 1))
                {
                    q.push({new_n, 0});
                    lev[new_n] = lev[cn] + 1;
                }
            }
        }
        else
        {
            for (int a = 1; a <= 6; a++)
            {
                int new_n = a + cn;
                if (new_n <= k && (lev[new_n] < lev[cn] + 1))
                {
                    q.push({new_n, 0});
                    lev[new_n] = lev[cn] + 1;
                }
            }
        }
    }
    return lev[k];
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vi v((n * n) + 1, 0);
    int nsq = n * n;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                v[k] = board[i][j];
                k++;
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                v[k] = board[i][j];
                k++;
            }
        }
    }
    vi lev(nsq + 1, INF);
    return bfs(v, lev, nsq);
}

int main()
{

    return 0;
}