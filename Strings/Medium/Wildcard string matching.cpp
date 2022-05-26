#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool match(string wild, string pattern)
{
    int n= wild.size();
    int m= pattern.size();
    bool dp[n+1][m+1];
    dp[n][m]=1;
    for(int j= m-1;j>=0;j--){dp[n][j]=0;}
    for(int i= n-1;i>=0;i--){
        if(wild[i]=='*'){
            dp[i][m] = dp[i+1][m];
        }
        else{
            dp[i][m] = 0;
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(wild[i]=='*'){
                dp[i][j] = dp[i+1][j] | dp[i][j+1];
            }
            else if(wild[i]=='?'){
                dp[i][j] = dp[i+1][j+1];
            }
            else{
                if(wild[i]== pattern[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[0][0];
}
int main(){
    
    return 0;
}