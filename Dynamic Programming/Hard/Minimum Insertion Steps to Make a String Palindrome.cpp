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
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
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

int minInsertions(string s)
{
    int n = s.size();
    vvi dp(n, vi(n, 1));
    for (int g = 1; g < n; g++)
    {
        int i = 0;
        for (int j = g; j < n; j++, i++)
        {
            if(g==1){
                if(s[i]==s[j]){
                    dp[i][j]=2;
                }
                else{dp[i][j]=1;}
            }
            else{
                if(s[i]==s[j]){
                    dp[i][j]= 2+ dp[i+1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
    }
    return n- dp[0][n-1];
}

int main()
{

    return 0;
}