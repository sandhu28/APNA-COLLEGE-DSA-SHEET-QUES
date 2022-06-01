#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool isMatch(string s, string ptr) {
    int n= s.size();
    int p = ptr.size();
    vector<vector<bool>> dp(p+1,vector<bool>(n+1,0));
    dp[0][0]= 1;
    for(int i=1;i<=p;i++){
        if(isalpha(ptr[i-1]) || (ptr[i-1]=='.')){
            dp[i][0]=0;
        }
        else{
            dp[i][0]= dp[i-2][0];
        }
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=n;j++){
            if(isalpha(ptr[i-1])){
                if(ptr[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
            }
            else if(ptr[i-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-2][j];
                if(ptr[i-2]== s[j-1] || (ptr[i-2]=='.')){
                    dp[i][j] = dp[i][j] | dp[i][j-1];
                }
            }
        }
    }
    return dp[p][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,p;
    cin>>s>>p;
    bool ans= isMatch(s,p);
    c(ans);
    return 0;
}