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

int setbit(int n){
    for(int i=31;i>=0;i--){
        if((1<<i)& n){
            return i;
        }
    }
}
vector<int> singleNumber(vector<int> nums) 
{
    int n= nums.size();
    int xr = 0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        xr ^= nums[i];
    }
    int pos = setbit(xr);
    int new_xor=0;
    for(int i=0;i<n;i++){
        if((1<<pos) & nums[i]){
            new_xor^= nums[i];
        }
    }
    ans.push_back(new_xor);
    ans.push_back(new_xor^xr);
    sort(ans.begin(),ans.end());
    return ans;

}
int main(){
    
    return 0;
}