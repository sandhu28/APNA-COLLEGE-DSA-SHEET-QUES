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

// bool isPal(string s,int i,int j){
//     bool f=1;
//     while(i<=j){
//         if(s[i]!=s[j]){
//             f=0;
//             break;
//         }
//         i++;j--;
//     }
//     return f==1;
// }

// int recur(string &s,int idx,int n){
//     if(idx==n){
//         return 0;
//     }
//     int mn= INT_MAX;
//         for(int j=idx;j<n;j++){
//             if(isPal(s,idx,j)){
//                 int curr= 1+ recur(s,j+1,n);
//                 mn= min(curr,mn);
//             }
//         }
//     return mn;
// }

int dpTable(string &s, vvi &isPal)
{
    int n = s.size();
    vi dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPal[i][j])
            {
                if (i == 0)
                {
                    if (dp[j + 1] == 2)
                    {
                        return 1;
                    }
                }
                if (1 + dp[j + 1] == 2)
                {
                    curr = 2;
                    break;
                }
                curr = min(curr, 1 + dp[j + 1]);
            }
        }
        dp[i] = curr;
    }
    return 0;
}

int minCut(string s)
{
    int n = s.size();
    vvi isPal(n, vi(n, 1));
    for (int g = 1; g < n; g++)
    {
        int i = 0;
        for (int j = g; j < n; j++, i++)
        {
            if (g == 1)
            {
                isPal[i][j] = s[i] == s[j] ? 1 : 0;
            }
            else
            {
                if (s[i] == s[j])
                {
                    isPal[i][j] = isPal[i + 1][j - 1] ? 1 : 0;
                }
                else
                {
                    isPal[i][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (isPal[0][i - 1] && isPal[i][j] && isPal[j + 1][n - 1])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    return 0;
}