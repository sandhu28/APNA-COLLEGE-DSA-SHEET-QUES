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

bool isValid(int t, vi &b, vi &p, int n, int m)
{
    int i = 0, j = 0;
    for (int i = 0; i < m; i++)
    {
        if (p[i] == t)
        {
            return 0;
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[b[i]] = 0;
    }
    vi temp;
    temp = p;
    temp.push_back(t);
    // ith p ko jth bus
    sort(all(temp));
    while (i < temp.size() && j < n)
    {
        if (p[i] == t)
        {
            while ((((t > b[j]) || (mp[b[j]] >= 2)) && (j < n)))
            {
                j++;
            }
            if (j < n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            while ((j < n) && (((temp[i] > b[j]) || (mp[b[j]] >= 2))))
            {
                j++;
            }
            if (j < n)
            {
                mp[b[j]] += 1;
            }
            else
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

// int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
//     sort(all(b));
//     sort(all(p));
//     int n= b.size();
//     int m= p.size();
//     int l=0;int h=1e9;
//     int ans= 0;
//     while(l<=h){
//         int mid= l+ (h-l)/2;
//         if(isValid(mid,b,p,n,m)){
//             ans= mid;
//             l= mid+1;
//         }
//         else{
//             h= mid-1;
//         }
//     }
//     return ans;

// }
int latestTimeCatchTheBus(vector<int> &b, vector<int> &p, int c)
{
    sort(all(b));
    sort(all(p));
    int n = b.size();
    int m = p.size();
    int i = 0, j = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[b[i]] = 0;
    }
    int idx = -1;
    while (i < m && j < n)
    {

        while ((j < n) && (((p[i] > b[j]) || (mp[b[j]] >= 2))))
        {
            j++;
        }
        if (j < n)
        {
            mp[b[j]] += 1;
        }
        else
        {
            idx = i;
            break;
        }
        i++;
    }
    if (idx == 0)
    {
        return b[n - 1];
    }
    if(idx==-1){
        idx=m-1;
    }
    int ans=0;
    for(int i=1;i<=idx;i++){
        if(p[i]!=p[i-1]){
            ans= p[i-1]-1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}