#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


int countBitsFlip(int a, int b){
    int ct=0;
    for(int i=31;i>=0;i--){
        int l= (1<<i)&a, r= (1<<i)&b;
        if(l^r){ct++;}
    }
    return ct;
}

int countBitsFlip(int a, int b){
    int xr= a^b;
    int ct=0;
    while(xr>0){
        xr= (xr)&(xr-1);
        ct++;
    }
    return ct;
}
int main(){
    
    return 0;
}