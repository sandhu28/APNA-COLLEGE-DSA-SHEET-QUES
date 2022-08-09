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
#define vs vector<string>
#define ss second
#define ff first
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

int main()
{
    fast_io;
    int t;
    cin >> t;
    int ct = 1;
    while (ct <= t)
    {
        int n;
        cin >> n;
        int l;
        cin >> l;
        vpii a(n);
        vpii b(n);
        vi fallTime(n);
        vi ans;
        vi direction(n, 0);
        fo(i, n)
        {
            int pos;
            cin >> pos;
            int dir;
            cin >> dir;
            direction[i] = dir;
            a[i] = {pos, i};
            if (dir)
            {
                fallTime[i] = l - pos;
            }
            else
            {
                fallTime[i] = pos;
            }
            b[i] = {fallTime[i], i};
        }
        sort(all(b));
        sort(all(a));
        int i = 0, j = n - 1;
        for (int k = 0; k < n; k++)
        {
            int m;
            m = k + 1;
            while (m < n && b[m].first == b[k].first)
            {
                m++;
            }
            vi temp;
            for (int it = k; it <= m - 1; it++)
            {
                if (direction[b[it].second])
                {
                    temp.push_back(a[j].ss);
                    j--;
                }
                else
                {
                    temp.push_back(a[i].ss);
                    i++;
                }
            }
            sort(all(temp));
            for (auto &x : temp)
            {
                ans.push_back(x);
            }
            k= m-1;
        }
        cout << ("Case #") << ct << ": ";
        for (auto &x : ans)
        {
            z(x+1);
        }
        nl;
        ct++;
    }

    return 0;
}