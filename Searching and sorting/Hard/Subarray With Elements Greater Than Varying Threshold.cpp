#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
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

void nextSmallerToRight(vi &nums,vi &nsr){
    int n=nums.size();
    stack<int> stk;
    stk.push(n-1);
    for(int i=n-2;i>0;i--){
        while(!stk.empty() && nums[stk.top()]>= nums[i]){
            stk.pop();
        }
        nsr[i]= stk.top();
        stk.push(i);
    }
}

void nextSmallerToLeft(vi &nums,vi &nsl){
    int n=nums.size();
    stack<int> stk;
    stk.push(0);
    for(int i=1;i<n-1;i++){
        while(!stk.empty() && nums[stk.top()]>= nums[i]){
            stk.pop();
        }
        nsl[i]= stk.top();
        stk.push(i);
    }
}

int validSubarraySize(vector<int>& nums, int threshold) {
    int n= nums.size();
    nums.insert(nums.begin(),0);
    nums.push_back(0);
    vi nsl(n+2,0);
    vi nsr(n+2,0);
    nextSmallerToLeft(nums,nsl);
    nextSmallerToRight(nums,nsr);
    for(int i=1;i<=n;i++){
        int l= nsr[i]-nsl[i]-1;
        int k= threshold/(l);
        if(nums[i]>k){
            return l;
        }
    }
    return -1;
}

int main(){
    
    return 0;
}