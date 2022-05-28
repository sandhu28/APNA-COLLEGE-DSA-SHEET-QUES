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

vector<int> spiralOrder(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> ans;
    int rst = 0, ren = n - 1, cst = 0, cen = m - 1;
    while (rst <= ren && cst <= cen)
    {

        if (rst <= ren && cst <= cen)
        {
            for (int col = cst; col <= cen; col++)
            {
                ans.push_back(v[rst][col]);
            }
        }

        rst++;

        if (rst <= ren && cst <= cen)
        {
            for (int row = rst; row <= ren; row++)
            {
                ans.push_back(v[row][cen]);
            }
        }

        cen--;
        if (rst <= ren && cst <= cen)
        {
            for (int col = cen; col >= cst; col--)
            {
                ans.push_back(v[ren][col]);
            }
        }
        ren--;
        if (rst <= ren && cst <= cen)
        {
            for (int row = ren; row <= rst; row--)
            {
                ans.push_back(v[row][cst]);
            }
        }
        cst++;
    }

    return ans;
}

vector<int> spiralOrder2(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> ans;
    int rst = 0, ren = n - 1, cst = 0, cen = m - 1;
    while (rst <= ren && cst <= cen)
    {
        c("yes");

        for (int col = cst; col <= cen; col++)
        {
            // ans.push_back(v[rst][col]);
            z(v[rst][col]);
        }

        rst++;

        for (int row = rst; row <= ren; row++)
        {
            ans.push_back(v[row][cen]);
            z(v[row][cen]);
        }

        cen--;

        for (int col = cen; col >= cst; col--)
        {
            ans.push_back(v[ren][col]);
            z(v[ren][col]);
        }

        ren--;

        for (int row = ren; row <= rst; row--)
        {
            ans.push_back(v[row][cst]);
            z(v[row][cst]);
        }

        cst++;
    }

    return ans;
}
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vvi v(n, vi(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> v[i][j];
        }
    }
    auto ans = spiralOrder2(v);
    for (auto &e : ans)
    {
        z(e);
    }

    return 0;
}