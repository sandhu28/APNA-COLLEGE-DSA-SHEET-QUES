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
#define vs vector<string>
#define ss second
#define ff first
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

int shortestSubarray(vector<int>& nums, int k) {

    int n= nums.size();
    vlli v(n);
    fo(i,n){
        v[i]= 1LL*nums[i];
    }
    int ans= INT_MAX;
    deque<int> dq;
    for(int i=0;i<n;i++){
        if(i>0){
            v[i]+= v[i-1];
        }
        if(v[i]>=k){
            ans= min(ans,(i+1));
        }
        while(dq.size()>0 && (v[i]-v[dq.front()])>=1LL*k){
            ans= min(ans,i-dq.front());
            dq.pop_front();
        }
        while(dq.size()>0 && (v[i]<= v[dq.back()])){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    return ans==INT_MAX?-1:ans;
}

int main(){
    
    return 0;
}