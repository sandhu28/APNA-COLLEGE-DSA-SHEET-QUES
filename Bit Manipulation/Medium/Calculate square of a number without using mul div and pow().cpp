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

// Approach one write a*a = a*(powers of 2 of a)
int calc_pow(int a){ 
    int ans=0;
    for(int i=31;i>=0;i--){
        if((1<<i)& (a)){
            ans += (a<<i);
        }
    }
    return ans;
}

// if n is even then 4*(sq(n/2)), if n is odd 4*sq(floor((n/2)) + 4*floor(n/2) + 1
int sq_rec(int a){
    if(a==0){return 0;}
    if(a==1){return 1;}
    if(a & 1){
        return (sq_rec((a>>1))<<2) + ((a>>1)<<2) + 1;
    }
    return ((sq_rec(a>>1)) <<2);
}


int main(){
    
    c(sq_rec(6));
    return 0;
}