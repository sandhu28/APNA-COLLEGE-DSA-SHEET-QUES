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

bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> st;
    for(int i=0;i<wordDict.size();i++){
        st.insert(wordDict[i]);
    }
    int n= s.size();
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        string curr= s.substr(0,i);
        for(int j=0;j<i;j++){
            string to_search= curr.substr(j);
            if(st.find(to_search)!= st.end()){
                dp[i] += dp[i- (to_search.size())];
            }
        }
    }
    return dp[n]>0;
}

int main()
{

    return 0;
}