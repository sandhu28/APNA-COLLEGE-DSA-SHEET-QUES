#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
// #define lli long long int
#define int long long
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

void merge(vi &v, int l, int mid, int h, vi &ans, vpii &vpr, vpii &temp)
{

    int k = l;
    int n = mid - l + 1;
    int m = h - mid;
    vi lft(n), rght(m);
    for (int i = l; i <= mid; i++)
    {
        lft[i - l] = (v[i]);
    }
    for (int i = mid + 1; i <= h; i++)
    {
        rght[i - mid - 1] = (v[i]);
    }

    int i = 0;
    int j = 0;
    int ct = 0;

    while ((i < n) && (j < m))
    {
        if (lft[i] < rght[j])
        {
            ans[vpr[i + l].second] += ct;
            temp[k] = vpr[i + l];
            v[k] = lft[i];
            k++;
            i++;
        }
        else if (lft[i] > rght[j])
        {
            ct++;
            v[k] = rght[j];
            temp[k] = vpr[j + mid + 1];
            k++;
            j++;
        }
        else
        {
            v[k] = lft[i];
            temp[k] = vpr[i + l];
            ans[vpr[i + l].second] += ct;
            k++;
            i++;
        }
    }
    while (i < n)
    {
        ans[vpr[i + l].second] += ct;
        v[k] = lft[i];
        temp[k] = vpr[i + l];
        k++;
        i++;
    }
    while (j < m)
    {
        v[k] = rght[j];
        temp[k] = vpr[j + mid + 1];
        k++;
        j++;
    }
    for (int t = l; t <= h; t++)
    {
        vpr[t] = temp[t];
    }
}

vi mergeSort(vi &v, int l, int h, vi &ans, vpii &vpr, vpii &temp)
{
    if (l >= h)
    {
        return ans;
    }
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergeSort(v, l, mid, ans, vpr, temp);
        mergeSort(v, mid + 1, h, ans, vpr, temp);

        merge(v, l, mid, h, ans, vpr, temp);
    }
    return ans;
}

vector<int> countSmaller(vector<int> &nums)
{
    vi ans(nums.size(), 0);
    vpii vpr(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        vpr[i] = {nums[i], i};
    }
    vpii temp(nums.size());
    return mergeSort(nums, 0, nums.size() - 1, ans, vpr, temp);
}
int32_t main()
{

    return 0;
}