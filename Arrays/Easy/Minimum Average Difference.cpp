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

int minimumAverageDifference(vector<int>& nums) {
    int n= nums.size();
    vi prefix(n,0);
    prefix[0] = nums[0];
    vi suffix(n,0);
    suffix[n-1]=0;
    lli sm=nums[0];
    for(int i=1;i<n;i++){
        sm+= 1LL*nums[i];
        prefix[i] = (sm)/(1LL*(i+1));
    }
    sm=0;
    for(int i=n-2;i>=0;i--){
        sm+= 1LL*nums[i+1];
        suffix[i] = (sm)/(1LL*(n- (i+1)));
    }
    int mn= INT_MAX;
    int idx=-1;
    for(int i=0;i<n;i++){
        int pre= prefix[i];
        int suf= suffix[i];
        int d= abs(pre - suf);
        if(d<mn){
            idx=i;
            mn= d;
        }
    }
    return idx;
}

int main(){
    
    return 0;
}