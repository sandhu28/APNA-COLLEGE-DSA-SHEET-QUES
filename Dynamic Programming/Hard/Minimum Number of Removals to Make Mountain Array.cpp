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
#define rep(i, k, n) for (int i = k; i < n; ++i)
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

int minimumMountainRemovals(vector<int> &nums)
{
    int n = nums.size();
    vi lisSt(n, 1);
    vi lisEn(n, 1);
    lisSt[0] = 1;
    lisEn[n - 1] = 1;
    vi v;
    v.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        auto it = lower_bound(all(v), nums[i]);
        if (it != v.end())
        {
            v[it - v.begin()] = nums[i];
            
        }
        else
        {
            v.push_back(nums[i]);
        }
        lisSt[i]= v.size();
    }
    v.clear();
    v.push_back(nums[n-1]);
    for (int i = n - 2; i >= 0; i--)
    {
        auto it = lower_bound(all(v), nums[i]);
        if (it != v.end())
        {
            v[it - v.begin()] = nums[i];
            
        }
        else
        {
            v.push_back(nums[i]);
        }
        lisEn[i]= v.size();
    }
    int mx = INT_MIN;
    for (int i = 1; i < n - 1; i++)
    {
        if (lisSt[i] == 1 || lisEn[i] == 1)
        {
            continue;
        }
        mx = max(mx, lisSt[i] + lisEn[i] - 1);
    }
    nl;
    return n - mx;
}

int main()
{

    return 0;
}