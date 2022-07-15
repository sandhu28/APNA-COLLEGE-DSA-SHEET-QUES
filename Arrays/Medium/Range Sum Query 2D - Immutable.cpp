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

class NumMatrix
{
private:
    vvi prefix;
    int r, c;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        r = n;
        c = m;
        vvi pre(n + 1, vi(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre[i][j] = pre[i-1][j] + pre[i][j-1] + pre[i-1][j-1];
            }
        }
        prefix = pre;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix[row2+1][col2+1] + prefix[row2+1][col1] + prefix[row1][col2+1] - prefix[row1][col1];
    }
};

int main()
{

    return 0;
}