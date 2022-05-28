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

void prt_indices(string s, string ptr)
{
    int mod = 1e9 + 7;
    int hp = 0;
    int hs = 0;
    int n = s.size();
    int p = ptr.size();
    for (int i = 0; i < p; i++)
    {
        hp = (hp * 1LL + ((ptr[i] - 'a') * 1LL * (iter_pow(26, p - 1 - i, mod))) % mod) % mod;
    }
    for (int i = 0; i < p; i++)
    {
        hs = ((hs * 1LL) + ((s[i] - 'a') * 1LL * (iter_pow(26, p - 1 - i, mod))) % mod) % mod;
    }
    bool t = true;
    if (hs == hp)
    {
        for (int i = 0; i < p; i++)
        {
            if (ptr[i] != s[i])
            {
                t = false;
                break;
            }
        }
    }
    for(int i=p;i<n;i++){
        hs = ((((hs-(iter_pow(26,s[i-p]-'a',mod)) + mod)%mod)*1LL*26) + ((s[i]-'a')))%mod;
        if(hs==hp){
            for (int j = 0; j < p; j++)
        {
            if (ptr[i] != s[i])
            {
                t = false;
                break;
            }
        }
        }
    }
}

int main()
{

    string s;
    cin >> s;
    string p;
    cin >> p;
    return 0;
}