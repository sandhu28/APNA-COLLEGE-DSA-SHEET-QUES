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

void recur(vvi &ans,vi &nums,vi &vec,int i,set<vi> s){
    if(i==nums.size()){
        return;
    }
    if(vec.empty() || (vec[vec.size()-1]< nums[i])){
        vec.push_back(nums[i]);
        if(vec.size()>=2){
            s.insert(vec);
        }
        recur(ans,nums,vec,i+1,s);
        vec.pop_back();
    }
    recur(ans,nums,vec,i+1,s);
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vvi ans;
    vi vec;
    set<vi> s;
    recur(ans,nums,vec,0,s);
    for(auto &v: s){
        ans.push_back(v);
    }
    
    return ans;
}

int main(){
    
    return 0;
}