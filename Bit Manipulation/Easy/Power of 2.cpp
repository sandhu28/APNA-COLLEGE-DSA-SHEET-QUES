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


bool isPowerofTwo(long long n){
    int ct=0;
    for(int i=63;i>=0;i--){
        if((1LL*1<<i )*1LL& n){
            ct++;
        }
    }
    return ct==1;
}
int main(){
    c(log2(6));
    return 0;
}