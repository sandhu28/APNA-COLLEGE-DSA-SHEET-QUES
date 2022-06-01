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
void dfs(vector<vector<char>> &board, vector<vector<bool>> &convert, int i, int j)
{
    int n = board.size(), m = board[0].size();
    convert[i][j] = 1;
    for (auto &pr : dir)
    {
        int nr = i - pr.first;
        int nc = j - pr.second;
        if ((nr < 0 || nr >= n || nc < 0 || nc >= m) || (convert[nr][nc] == 1) || (board[nr][nc] == 'X'))
        {
            continue;
        }
        dfs(board, convert, nr, nc);
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> convert(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if ((board[i][j] == 'O') && (convert[i][j] == 0))
                {
                    // cout<<"indices"<<" "<<i<<" "<<j<<endl;
                    dfs(board, convert, i, j);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout<<(convert[i][j])<<" ";
            if (convert[i][j] == 0)
            {
                board[i][j] = 'X';
            }
        }
        cout << endl;
    }
}

int main()
{

    return 0;
}