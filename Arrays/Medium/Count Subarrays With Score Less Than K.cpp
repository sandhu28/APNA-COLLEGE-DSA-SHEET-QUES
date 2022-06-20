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


long long countSubarrays(vector<int>& nums, long long k) {
    int n= nums.size();  
    lli sm=0;
    int i=0;int j=0;
    lli ct=0;
    while(j<n){
        sm+= 1LL*nums[j];
        int l= j-i+1;
        lli pro= sm *1LL* l;
        if(pro<k){
            j++;
            // ct++;
        }
        else{
            int n= j-i;
            // ct += (n*1LL*(n+1))/2;
            while(((sm)*1LL*(j-i+1))>=k && (i<=j)){
                sm-= 1LL*nums[i];
                ct+= j-i;
                i++;
            }
            // sm-= nums[j];
            // i=j;
            j++;
            // if(i>j){
            //     j++;
            // }
            // else{
            //     // if(j!=n-1){
            //     //     ct++;
            //     // }
            //     j++;
            // }
            
        }
    }
    while(i<n){
        ct+= j-i;
        i++;
    }
    return ct;
}

int main(){
    
    return 0;
}