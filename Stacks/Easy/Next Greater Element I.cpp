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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ngr;
    stack<int> stk;
    int n1= nums1.size(), n2= nums2.size();
    vector<int> idx(1e4+2);
    // use unordered_map to reduce space
    vector<int> ans;
    for(int i=n2-1;i>=0;i--){
        idx[nums2[i]] = i;
        while(!stk.empty()){
            int t= stk.top();
            if(t>nums2[i]){
                ngr.push_back(t);
                break;
            }
            else{
                stk.pop();
            }
        }
        if(stk.empty()){ngr.push_back(-1);}
        stk.push(nums2[i]);
    }
    reverse(ngr.begin(),ngr.end());
    for(int i=0;i<n1;i++){
        ans.push_back(ngr[idx[nums1[i]]]);
    }
    return ans;
}


int main(){
    
    return 0;
}