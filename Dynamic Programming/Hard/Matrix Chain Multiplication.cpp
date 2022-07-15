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

int recur(vi &v,int i,int j){
    if(i>=j){
        return 0;
    }
    int ans= INT_MAX;
    for(int k=i;k<j;k++){
        int left= recur(v,i,k);
        int right= recur(v,k+1,j);
        int curr=  v[i]*v[k+1]*v[j+1];
        int temp= left+right+curr;
        // if(i==0 && j==v.size()-2){
        //     z(i);z(k);c(left);
        //     z(k+1);z(j);c(right);
        //     z(i);z(j);c(temp);
        // }
        if(temp<ans){
            ans=temp;
        }
    }
    return ans;
}

int dp_table(vi &v)
{
    int n = v.size();
    n = n - 1;
    vvi dp(n, vi(n, 0));
    for (int g = 1; g < n; g++)
    {
        int i = 0;
        for (int j = g; j < n; j++, i++)
        {
            if (g == 1)
            {
                dp[i][j] = v[i] * v[j] * v[j + 1];
            }
            else
            {
                int mn = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int temp = dp[i][k] + dp[k + 1][j] +( v[i] * v[k + 1] * v[j+1]);
                    if (temp < mn)
                    {
                        mn = temp;
                    }
                }
                dp[i][j]= mn;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         z(dp[i][j]);
    //     }
    //     nl;
    // }
    return dp[0][n-1];
}

int main()
{
    fast_io;
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    c(dp_table(v));
    c(recur(v,0,n-2));

    return 0;
}