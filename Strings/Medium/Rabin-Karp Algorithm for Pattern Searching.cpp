#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

// For the case when input has only small alphabets

int iter_pow(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (1 & (b))
        {
            ans = ((ans) % m * (a) % m) % m;
        }
        b = (b >> 1);
        a = ((a % m) * (a % m)) % m;
    }
    return ans;
}

vector<int> prt_indices(string s, string ptr)
{
    int mod = 1e9 + 7;
    int hp = 0;
    int hs = 0;
    int n = s.size();
    int p = ptr.size();
    // c(p);
    vector<int> ans;
    for (int i = 0; i < p; i++)
    {
        hp = ((hp * 1LL) + (((ptr[i] - 'a' + mod)%mod) * 1LL * (iter_pow(10, p - 1 - i, mod))) % mod) % mod;
    }
    // c(hp);
    for (int i = 0; i < p; i++)
    {
        hs = ((hs * 1LL) + (((s[i] - 'a' + mod)%mod) * 1LL * (iter_pow(10, p - 1 - i, mod))) % mod) % mod;
    }
    // c(hs);
    int t=0;
    if (hs == hp)
    {
        for (int i = 0; i < p; i++)
        {
            if (ptr[i] == s[i])
            {
                t++;
            }
        }
    }
    if(t==p){ans.push_back(0);}
    for (int i = p; i < n; i++)
    {
        hs = ((((hs - ((s[i - p] - 'a') * 1LL * iter_pow(10, p - 1, mod)) + mod) % mod) * 1LL * 10) + ((s[i] - 'a'))) % mod;
        // cout<<i<<" "<<(hs);nl;
        if (hs == hp)
        {
            if(s.substr(i-p+1,p)== ptr){
                ans.push_back(i-p+1);
            }
        }
    }
    return ans;
}

int main()
{

    string s;
    cin >> s;
    string p;
    cin >> p;
    auto ans= prt_indices(s,p);
    for(auto& e: ans){
        z(e);
    }
    // c(iter_pow(26,8,1e9+7));
    return 0;
}