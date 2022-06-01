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

int copy(int a,int b,int r,int l){
    // a ki bits ko b mein copy karna hai.
    int m1= 1;
    int m2 = (((1<<r-l+1)-1)<<(l));
    return (m2&a) | b;
}

int main(){
    int a,b,l,r;
    cin>>a>>b>>l>>r;
    c(copy(a,b,l,r));
    return 0;
}