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

// Way one had to think of many conditions due to which many wrong test cases are there.
bool recur(vector<vector<char>> &board, int n, int m, string &word, int sz, int i, int j, int idx, vector<vector<bool>> &vis)
{
    if (idx == sz)
    {
        return true;
    }
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    vis[i][j] = 1;
    if (board[i][j] == word[idx])
    {
        for (auto &pr : dir)
        {
            int ki = i - pr.first, kj = j - pr.second;
            if (ki >= 0 && ki < n && kj >= 0 && kj < m)
            {
                if (idx == sz - 1)
                {
                    return true;
                }
                if (vis[ki][kj])
                {
                    continue;
                }
            }
            if (recur(board, n, m, word, sz, i - pr.first, j - pr.second, idx + 1, vis))
            {
                return true;
            }
        }
    }
    vis[i][j] = 0;
    return 0;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size();
    int sz = word.size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                if (recur(board, n, m, word, sz, i, j, 0, vis))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// A better way to think about
bool recur(vector<vector<char>> &board, int n, int m, string &word, int sz, int i, int j, int idx, vector<vector<bool>> &vis)
{
    vis[i][j] = 1;
    if (idx == sz - 1)
    {
        return true;
    }
    for (auto &pr : dir)
    {
        int nr = i - pr.first;
        int nc = j - pr.second;
        if ((nr<0 || nr >= n || nc < 0 || nc >=m) || (vis[nr][nc]=1))
        {
            continue;
        }
        if(board[nr][nc]== word[idx+1]){
            if(recur(board, n, m, word, sz, i - pr.first, j - pr.second, idx + 1, vis)){
                return true;
            }
        }
        
    }
    vis[i][j] = 0;
    return 0;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size();
    int sz = word.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (board[i][j] == word[0])
            {
                vector<vector<bool>> vis(n, vector<bool>(m, 0));
                if (recur(board, n, m, word, sz, i, j, 0, vis))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{

    c(toupper('A'));
    return 0;
}