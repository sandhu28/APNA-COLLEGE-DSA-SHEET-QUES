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

    
int minTaps(int n, vector<int> &ranges)
{
    // int n = ranges.size();
    vvi v(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        int a = i - ranges[i];
        int b = i + ranges[i];
        v[i] = {a, b};
        // z(a);z(" ");c(b);
    }

    sort(all(v), [](vi &a, vi &b)
         {
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0]; });
        int i = 0;
    int cen = INT_MIN;
     if ( v[0][0]>0)
    {
        return -1;
    }
    while(i<n+1){
        if(v[i][0]<=0){
            if(v[i][1]>cen){
                cen= v[i][1];
                if(cen>=n){return 1;}
            }
        }
        else{
            break;
        }
        i++;
    }

    // int cst = v[0][0];
    
    // z(cst);z("yes");z(cen);
    int ct = 1;

    while (i < n + 1)
    {
        bool f = 0;
        int temp = -1;
        while ((i < n + 1) && (v[i][0] <= cen))
        {
            if (v[i][1] > cen)
            {
                f = 1;
                temp= max(temp,v[i][1]);
            }
            i++;
        }
        if (f == 0)
        {
            return -1;
        }
        cen = temp;
        ct++;
        if(cen>=n){
            return ct;
        }
    }
    if(cen>=n){
        return ct;
    }
    return -1;
}

int main()
{

    return 0;
}