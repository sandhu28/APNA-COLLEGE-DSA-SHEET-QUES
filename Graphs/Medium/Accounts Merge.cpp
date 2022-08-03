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

string find(string &s, map<string, string> &par)
{
    if (par[s] == s)
    {
        return s;
    }
    return par[s] = find(par[s], par);
}

vector<vector<string>> accountsMerge(vector<vector<string>> &acc)
{
    map<string, string> owner;
    map<string, string> par;
    map<string, set<string>> g;
    int n = acc.size();
    fo(i, n)
    {
        foe(j, 1, acc[i].size())
        {
            owner[acc[i][j]] = acc[i][0];
            par[acc[i][j]] = acc[i][j];
        }
    }
    fo(i, n)
    {
        string p = find(acc[i][1], par);
        foe(j, 2, acc[i].size())
        {
            par[find(acc[i][j], par)] = p;
        }
    }
    fo(i, n)
    {
        foe(j, 1, acc[i].size())
        {
            g[owner[find(acc[i][j], par)]].insert(acc[i][j]);
        }
    }
    vector<vector<string>> ans;
    for (auto &pr : g)
    {
        vector<string> temp(pr.second.begin(), pr.second.end());
        temp.insert(temp.begin(), pr.first);
        ans.push_back(temp);
    }
    return ans;
}

void dfs(int i, set<string> &st, map<string, vi> &m, vi &vis, vector<vector<string>> &ac)
{
    if (vis[i])
    {
        return;
    }
    vis[i] = 1;
    foe(j, 1, ac[i].size())
    {
        st.insert(ac[i][j]);
        for (auto &child : m[ac[i][j]])
        {
            dfs(child, st, m, vis, ac);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &ac)
{

    vector<vector<string>> ans;
    int n = ac.size();
    vi vis(n, 0);
    map<string, vi> m;
    fo(i, n)
    {
        foe(j, 1, ac[i].size())
        {
            m[ac[i][j]].push_back(i);
        }
    }

    fo(i, n)
    {
        set<string> st;
        if (vis[i])
        {
            continue;;
        }
        dfs(i, st, m, vis, ac);
        vector<string> temp(st.begin(),st.end());
        temp.insert(temp.begin(),ac[i][0]);
        ans.push_back(temp);
    }
    return ans;

}

int main()
{

    return 0;
}