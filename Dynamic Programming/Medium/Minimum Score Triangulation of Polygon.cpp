#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int minScoreTriangulation(vector<int>& v) {
    int n= v.size();
    vvi dp(n,vi(n,0));
    for(int g=2;g<n;g++){
        int i=0;
        for(int j=g;j<n;j++,i++){
            if(g==2){
                dp[i][j]= v[i]*v[i+1]*v[j];
            }
            else{
                int mn= INT_MAX;
                for(int k=i+1;k<j;k++){
                    int curr= v[i]*v[k]*v[j];
                    int left= dp[i][k];
                    int right= dp[k][j];
                    int temp= left+right+curr;
                    if(temp<mn){
                        mn= temp;
                    }
                }
                dp[i][j]= mn;
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    
    return 0;
}