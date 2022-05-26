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

int mx_sum(vi &v){
    int sm=0;
    int mx_sm=INT_MIN;
    int n= v.size();
    int sm2=0;
    int mn_sm= INT_MAX;
    for(int i=0;i<n;i++){
        sm+= v[i];
        mx_sm= max(mx_sm, sm);
        if(sm<0){
            sm=0;
        }
        sm2+= v[i];
        mn_sm= min(mn_sm,sm2);
        if(sm2>0){
            sm2=0;
        }
    }
    return max(abs(mn_sm),abs(mx_sm));
}
int maxAbsoluteSum(vector<int>& nums) {
    return mx_sum(nums);
}

int main(){
    
    return 0;
}