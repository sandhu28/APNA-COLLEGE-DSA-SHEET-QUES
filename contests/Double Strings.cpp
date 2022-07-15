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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        multiset<string> ms;
        rep(i, 0, n)
        {
            cin >> v[i];
            ms.insert(v[i]);
        }
        string ans="";
        for (int i = 0; i < n; i++)
        {
            bool f=0;
            for (int k = 0; k< v[i].size()-1; k++)
            {
                string a=v[i].substr(0, k + 1);
                // c(a);
                if (ms.find(v[i].substr(0, k + 1)) != ms.end())
                {
                    // string b= v[i].substr(k + 1);
                    if (ms.find(v[i].substr(k + 1)) != ms.end())
                    {
                        f=1;break;
                    }
                }
            }
            if(f){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
        }
        c(ans);
    }

    return 0;
}