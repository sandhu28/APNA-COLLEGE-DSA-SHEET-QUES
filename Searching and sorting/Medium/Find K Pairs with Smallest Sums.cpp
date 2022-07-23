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

vector<vector<int>> kSmallestPairs(vector<int> &arr1, vector<int> &arr2, int k)
{
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    vector<vector<int>> ans;
    int n = arr1.size();
    int m = arr2.size();
    lli sz = m * 1LL * n;
    if (sz <= 1e4)
    {
        if (k * 1LL > m * n)
        {
            k = m * n;
        }
    }
    fo(j, m)
    {
        pair<int,pii> temp;
        temp.first= arr1[0] + arr2[j];
        temp.second = {0, j};
        pq.push(temp);
    }
    fo(i, k)
    {
        auto top = pq.top();
        pq.pop();
        int x = top.second.first;
        int y = top.second.second;
        ans.push_back({arr1[x], arr2[y]});
        if (x == n - 1)
        {
            continue;
        }
        pq.push({arr1[x + 1] + arr2[y], {x + 1, y}});
    }
    return ans;
}

int main()
{

    return 0;
}