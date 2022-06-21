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
// #define fast_io                       
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

lli recur(vvi &v,int r,int c,vvi &memo){
    if(r==1 && c==1){
        return v[r][c];
    }
    if(memo[r][c]!=-1){
        return memo[r][c];
    }
    lli ans= v[r][c];
    for(int j=1;j<c;j++){
        ans= max(ans,recur(v,r,c-j,memo) + recur(v,r,j,memo));
    }
    for(int i=1;i<r;i++){
        ans= max(ans,recur(v,r-i,c,memo) + recur(v,i,c,memo));
    }
    return memo[r][c]= ans;
}

long long sellingWood(int m, int n, vector<vector<int>> &prices)
{
    vvi v(m+1,vi(n+1,0));
    for(int i=0;i<prices.size();i++){
        v[prices[i][0]][prices[i][1]] = prices[i][2];
    }
    vvi memo(m+1,vi(n+1,-1));
    return recur(v,m,n,memo);
    // return 1;

}

int main()
{

    return 0;
}