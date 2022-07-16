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
    while (t--)
    {
        int n;
        cin >> n;
        vlli v(n);
        int fNonZero = -1;
        fo(i, n)
        {
            cin >> v[i];
        }
        fo(i, n)
        {
            if (v[i] != 0)
            {
                fNonZero = i;
                break;
            }
        }
        if (fNonZero == n - 1 || fNonZero==-1)
        {
            c('0');
            continue;
        }
        vlli pre(n, 0);
        pre[0] = v[0];
        foe(i, 1, n)
        {
            pre[i] = pre[i - 1] + 1LL * v[i];
        }
        lli ans = 0;
        for (int i = fNonZero + 1; i < n - 1;)
        {
            int ct = 0;
            if (v[i] == 0)
            {
                while ((i < n - 1) && (v[i] == 0))
                {
                    ct++;
                    i++;
                }
                ans = ans + 1LL * ct;
                // ans = ans + pre[i - 1];
            }
            else{
                i++;
            }
        }
        ans= ans+ 1LL*pre[n-2];
        c(ans);
    }

    return 0;
}