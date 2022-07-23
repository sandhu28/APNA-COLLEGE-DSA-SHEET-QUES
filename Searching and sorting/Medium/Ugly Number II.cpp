#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
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

int nthUglyNumber(int n)
{
    if (n <= 5)
    {
        return n;
    }
    set<lli> st;
    st.insert(1);

    fo(i,n-1){
        lli val= *st.begin();
        st.erase(st.begin());
        st.insert(val*1LL*2);
        st.insert(val*1LL*3);
        st.insert(val*1LL*5);
    }
    return (int)(*st.begin());
}
int nthUglyNumber(int n)
{
    if(n==1){
        return 1;
    }
    vi dp(n,1);
    int p2=0,p3=0,p5=0;
    for(int i=1;i<n;i++){
        dp[i]= min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
        if(dp[i]== dp[p2]*2){p2++;}
        if(dp[i]== dp[p3]*3){p3++;}
        if(dp[i]== dp[p5]*5){p5++;}
    }
    return dp[n-1];
}

int main()
{

    return 0;
}