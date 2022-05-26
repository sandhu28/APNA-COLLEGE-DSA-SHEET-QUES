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

// DP approach storing all previous values
int maxProduct(vector<int>& nums) {
    int n = nums.size(), maxProd = -INF;
    vector<vector<int>> dp(n+1, vector<int>(2,1));
    for (int i = 0;i<n;i++) {
        if (nums[i]>0) {
            dp[i+1][0] = max(nums[i], dp[i][0]*nums[i]);
            dp[i+1][1] = min(nums[i], dp[i][1]*nums[i]);
        } else {
            dp[i+1][0] = max(dp[i][1]*nums[i], nums[i]);
            dp[i+1][1] = min(dp[i][0]*nums[i], nums[i]);
        }
        maxProd = max(maxProd, dp[i+1][0]);
    }
    return maxProd;
}

// Optimised DP approach knowing that only previous index's min and max are required.
int maxProduct(vector<int>& v) {
    int n= v.size();
    int mx_pro =v[0];
    int mn_pro= v[0];
    int ans= v[0];
    for(int i=1;i<n;i++){
        if(v[i]<0){
            swap(mx_pro,mn_pro);
        }
        mx_pro = max(v[i],v[i]*mx_pro);
        mn_pro= min(v[i],v[i]*mn_pro);
        ans= max(mx_pro,ans);
    }
    return ans;
}

int main(){
    
    return 0;
}