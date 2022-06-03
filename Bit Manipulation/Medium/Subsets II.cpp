#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = {{}};
    for (int i = 0; i < n; i++)
    {
        int ct = 1;
        while (ct + i < n && (nums[ct + i] == nums[i]))
        {
            ct++;
        }
        for (auto &vec : ans)
        {
            for (int j = 0; j < ct; j++)
            {
                vec.push_back(nums[i]);
                ans.push_back(vec);
            }
        }
        i+= (ct-1);
    }
    return ans;
}

int main()
{

    return 0;
}