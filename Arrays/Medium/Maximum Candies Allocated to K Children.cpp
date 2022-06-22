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

bool isValid(int mid,vi &candies,lli k){
    int ch= 0;
    for(auto &e: candies){
        if(e>=mid){
            ch+= e/mid;
        }
    }
    return ch>= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    lli sm=0;
    for(auto &e: candies){
        sm+= e;
    }    
    if(sm<k){
        return 0;
    }
    int l=1,h= 1e7;
    int ans= 0;
    while(l<=h){
        int mid= l + (h-l)/2;
        if(isValid(mid,candies,k)){
            ans= mid;
            l= mid+1;
        }
        else{
            h= mid-1;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}