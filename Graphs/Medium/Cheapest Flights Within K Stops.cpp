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

int findCheapestPrice(int n, vector<vector<int>> &f, int src, int dst, int k)
{

    vector<vector<pii>> g(n);
    for (int i = 0; i < f.size(); i++)
    {
        g[f[i][0]].push_back({f[i][1], f[i][2]});
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int ans = INT_MAX;
    pq.push({0, {src, 0}});
    vi cost(n, INT_MAX);
    vi stops(n, INT_MAX);
    cost[src] = 0;
    stops[src] = 0;
    while (!pq.empty())
    {
        auto pr = pq.top();
        pq.pop();
        int c_cost = pr.first;
        int c_node = pr.second.first;
        int c_k = pr.second.second;
        if (c_cost > cost[c_node] && c_k > stops[c_node])
        {
            continue;
        }

        if (c_node == dst)
        {
            if (c_k <= k + 1)
            {
                ans = min(ans, pr.first);
            }
        }
        for (auto &child : g[c_node])
        {
            if ((c_cost + child.second < cost[child.first]) || (c_k + 1 < stops[child.first]))
            {
                if (child.first != dst && (c_k + 1 >= k + 1))
                {
                    continue;
                }
                else if (child.first == dst)
                {
                    if (c_k + 1 > k + 1)
                    {
                        continue;
                    }
                }

                pq.push({pr.first + child.second, {child.first, pr.second.second + 1}});
                cost[child.first] = pr.first + child.second;
                stops[child.first] = c_k + 1;
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
int main()
{

    return 0;
}