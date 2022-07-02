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

vi ways(string s)
{
    
    vi ans;
    if(s.size()==1){
        ans.push_back(stoi(s));
        return ans;
    }
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if ((ch == '*') || (ch == '-') || ch == '+')
        {
            string a = s.substr(0, i);
            string b = s.substr(i + 1);
            vi v1 = ways(a);
            vi v2 = ways(b);
            for (auto &x : a)
            {
                for (auto &y : b)
                {
                    if (ch == '*')
                    {
                        ans.push_back(x*y);
                    }
                    else if(ch=='+'){
                        ans.push_back(x+y);
                    }
                    else{
                        ans.push_back(x-y);
                    }
                }
            }
        }
    }
    return ans;
}

vector<int> diffWaysToCompute(string s)
{
    return ways(s);
}

int main()
{

    return 0;
}