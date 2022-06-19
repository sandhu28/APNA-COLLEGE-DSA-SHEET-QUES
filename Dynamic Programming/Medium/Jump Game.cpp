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

bool canJump(vector<int> &nums)
{

    int n= nums.size();
    vector<int> dp(n,0);
    dp[n-1]=1;
    for(int i=n-2;i>=0;i--){
        int mxJumps = nums[i];
        if(mxJumps==0){
            dp[i]=0;continue;
        }
        for(int j= 1;(i+j<= n-1) && (j<=mxJumps) ;j++){
            if(dp[i+j]==1){
                dp[i]=1;
                break;
            }
        }
    }
    return dp[0];

}

int main()
{

    return 0;
}