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
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int recur(int i,int j,vi &cuts,vvi &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans= INT_MAX;
    for(int k=i;k<=j;k++){
        int cost = (cuts[j+1]-cuts[i-1])+ recur(i,k-1,cuts,dp)+ recur(k+1,j,cuts,dp);
        ans= min(ans,cost);
    }
    return dp[i][j]= ans;
}

int dpTab(vi &cuts,int n){
    int sz= cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    vvi dp(sz+1,vi(sz+1,0));
    for(int g=0;g<sz;g++){
        int i=1;
        for(int j=g+1;j<sz+1;j++,i++){
            int ans=INT_MAX;
            for(int k=i;k<=j;k++){
                int temp= dp[i][k-1]+ dp[k+1][j]+ cuts[j+1] -cuts[i-1];
                ans= min(ans,temp);
            }
            dp[i][j]= ans;
        }
    }
    return dp[1][sz];
}

int minCost(int n, vector<int>& cuts) {
    int sz= cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(all(cuts));
    int i=1,j=sz;
    vvi dp(sz+1,vi(sz+1,-1));
    return recur(i,j,cuts,dp);
}

int main(){


    
    return 0;
}