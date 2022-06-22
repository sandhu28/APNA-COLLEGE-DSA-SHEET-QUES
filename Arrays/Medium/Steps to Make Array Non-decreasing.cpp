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

int totalSteps(vector<int> &nums)
{
    int n = nums.size();
    stack<pii> stk; // index , steps
    stk.push({0, 0});
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        auto pr = stk.top();
        int ct=0;
        while (!stk.empty() && (nums[i] >= nums[stk.top().first]))
        {
            ct= max(ct,stk.top().second);
            stk.pop();
        }
        if (!stk.empty())
        {
            ct+=1;
        }
        else
        {
            ct=0;
        }
        ans= max(ans,ct);
        stk.push({i,ct});
    }
    return ans;
}

int main()
{

    return 0;
}