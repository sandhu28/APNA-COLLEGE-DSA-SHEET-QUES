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

vector<int> largestDivisibleSubset(vector<int> &v)
{
    int n = v.size();
    sort(all(v));
    vi hash(n, -1);
    int mxIdx = -1;
    int mx = 1;
    vi dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[i] % v[j] == 0)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
        }
        if (dp[i] > mx)
        {
            mxIdx = i;
            mx = dp[i];
        }
    }
    int i= mxIdx;
    vi ans;
    while(i>=0){
        ans.push_back(v[i]);
        i= hash[i];
    }
    reverse(all(ans));
    return ans;
}

int main()
{

    return 0;
}