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

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{

    int n = points.size();
    priority_queue<pair<int, pii>> pq;
    for (int i = 0; i < n; i++)
    {
        int a = points[i][0];
        int b = points[i][1];
        int d = a * a + b * b;
        pq.push({d, {a, b}});
        int sz = pq.size();
        if (sz > k)
        {
            pq.pop();
        }
    }
    vvi ans;
    while (!pq.empty())
    {
        vi temp(2);
        temp[0] = pq.top().second.first;
        temp[1] = pq.top().second.second;
        ans.push_back(temp);
        pq.pop();
    }
    return ans;
}

int main()
{

    return 0;
}