#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (i = k; i < n; ++i)
#define Repr(i,k,n) for (i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


void nextPermutation(vector<int>& nums) {
    int idx=-1;
    bool t=false;
    bool brk = false;
    for(int i=nums.size()-2;i>=0;i--){
        if(brk){
            break;
        }
        if(nums[i]>=nums[i+1]){
            continue;
        }
        else{
            brk = true;
            t=true;
            for(int j= nums.size()-1;j>i;j--){
                if(nums[j]>nums[i]){
                    swap(nums[j],nums[i]);
                    reverse(nums.begin()+i+1,nums.end());
                    break;
                }
            }
        }
    }
    if(!t){
        reverse(nums.begin(),nums.end());
    }
}

int main(){
    
    return 0;
}