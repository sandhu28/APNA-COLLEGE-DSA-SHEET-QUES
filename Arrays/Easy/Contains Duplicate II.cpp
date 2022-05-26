#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (i = k; i < n; ++i)
#define Repr(i, k, n) for (i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

//Sol 1 --> Used two for loops. 
bool containsNearbyDuplicate1(vector<int> &nums, int k)
{
    unordered_map<int, vector<int>> um;

    for (int i = 0; i < nums.size(); i++)
    {
        if (um.find(nums[i]) != um.end())
        {

            vi indices = um[nums[i]];
            for (int j = 0; j < indices.size(); j++)
            {
                if (abs(indices[j] - i) <= k)
                {
                    return true;
                }
            }
        }
        um[nums[i]].push_back(i);
    }
    return false;
}

// sol 2 --> Using just a single loop
bool containsNearbyDuplicate2(vector<int> &nums, int k)
{
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); i++)
    {
        if (um.count(nums[i]))
        {
            if (abs(um[nums[i]] - i) <= k)
            {
                return true;
            }
        }
        um[nums[i]] = i;
    }
    return false;
}

// Sol 3 --> A little diff thinking. 
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> us;
    if(k>= nums.size()){
        k= nums.size()-1;
    }
    if(k==0){
        return false;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if(i>k){
            us.erase(us.find(nums[i-k-1]));
        }
        if(us.find(nums[i])!= us.end()){
                return true;
        }
        us.insert(nums[i]);
    }
    return false;
}

int main()
{

    return 0;
}