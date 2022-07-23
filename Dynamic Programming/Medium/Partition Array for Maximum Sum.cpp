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

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n= arr.size();
    vi dp(n+1,0);
    dp[n-1]= arr[n-1];
    for(int i=n-2;i>=0;i--){
        int mx= INT_MIN;
        int smx=0;
        for(int j=i;j<n;i++){
            mx = max(arr[j],arr[i]);
            if(j-i+1>k){
                break;
            }
            int left= mx*(j-i+1);
            smx= max(smx,left+dp[j+1]);
        }
        dp[i]=smx;
    }
    return dp[0];
}

int main(){
    
    return 0;
}