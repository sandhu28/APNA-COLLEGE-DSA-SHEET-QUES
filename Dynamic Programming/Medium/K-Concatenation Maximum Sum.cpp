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

lli kadanes(vi &v)
{
    int M = 1e9 + 7;
    int n = v.size();
    lli mx = LLONG_MIN;
    lli sm = 0;
    fo(i, n)
    {
        sm += 1LL * v[i];
        mx = max(mx, sm);
        if (sm < 0)
        {
            sm = 0;
        }
    }
    return mx;
}

int kConcatenationMaxSum(vector<int> &v, int k)
{
    int n = v.size();
    if (k == 1)
    {
        lli ans = kadanes(v);
        return (int)(ans % M);
    }
    lli sm = 0;
    fo(i, n)
    {
        sm += v[i];
    }
    vi temp = v;
    fo(i, n)
    {
        temp.push_back(v[i]);
    }
    lli ans = kadanes(temp);
    if (sm <= 0)
    {
        return (int)(ans % M);
    }
    ans+= (k-2)*1LL*(sm);
    return (int)(ans % M);
    
}

int main()
{

    return 0;
}