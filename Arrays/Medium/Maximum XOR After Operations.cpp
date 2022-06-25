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

int ct_bits(int n){
    for(int i=31;i>=0;i--){
        if(n &( 1<< i)){
            return i + 1;
        }
    }
    return -1;
}

int maximumXOR(vector<int>& nums) {
    int n= nums.size();
    sort(nums.begin(),nums.end());
    int bits= ct_bits(nums[n-1]);
    if(bits==-1){return 0;}
    vi temp(bits);
    for(int i=0;i<bits;i++){
        for(auto &k: nums){
            if((1<<i) & k ==0){
                temp[i] ++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<bits;i++){
        if(temp[i]!=nums.size()){
            ans |= (1<<i);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}