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
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int i = 0;
    int j = 0;
    lli ct = 0;
    map<int, int> m;
    while (j < n)
    {
        m[v[j]]++;
        if (m.size() > k)
        {
            while (m.size() > k)
            {
                ct += j - i;
                m[v[i]]--;
                if (m[v[i]] == 0)
                {
                    m.erase(v[i]);
                }
                i++;
            }
        }
        j++;
    }
    while (i < n)
    {
        ct += j - i;
        // m[v[i]]--;
        // if (m[v[i]] == 0)
        // {
        //     m.erase(m[v[i]]);
        // }
        i++;
    }
    c(ct);
    return 0;
}