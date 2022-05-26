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

//Approach one which stores largest till now from back
int maxProfit(vector<int>& prices) {
    int n= prices.size();
    vector<int> temp(n);
    temp[n-1]= prices[n-1];
    for(int i=n-2;i>=0;i--){
        temp[i] = max(prices[i],temp[i+1]);
    }
    int mx=-2;
    rep(i,0,n-1){
        mx = max(mx, temp[i+1]- prices[i]);
    }
    return mx<0?0:mx;

}

// Approach two Kadane's alogrithm-- same as max subarray sum pb. 
int maxProfit(vector<int>& prices) {
    int n= prices.size();
    int mx_diff=0;int mx=INT_MIN;
    for(int i=1;i<n;i++){
        mx_diff += prices[i]-prices[i-1];
        mx= max(mx_diff, mx);
        if(mx_diff<0){
            mx_diff=0;
        }
    }
    return mx;

}

int main(){
    
    return 0;
}