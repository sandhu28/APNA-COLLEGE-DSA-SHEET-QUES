#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int iter_pow(int a,int b){
    int ans=1;
    while(b>0){
        if(1&b){
            ans= ans * a;
        }
        b>>= 1;
        a = a*a;
    }
    return ans;
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n= nums.size();
    int times= iter_pow(2,n);
    for(int i=0;i< times;i++){
        vector<int> temp;
        for(int j=31;j>=0;j--){
            if((1<<j) & i){
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;

}

int main(){
    
    return 0;
}