#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
// #define ll int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool check(vlli &machine,lli p,lli t){
    lli n= machine.size();
    lli tot=0;
    for(int i=0;i<n;i++){
        tot += min(t/machine[i],(lli)1e9);
    }
    // if(tot<0){
    //     tot= LLONG_MAX;
    // }
    return tot>=p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,noOfProducts;cin>>n>>noOfProducts;
    vector<lli> machine(n);
    for(int i=0;i<n;i++){
        cin>>machine[i];
    }
    lli l=0,h=1e18+10;
    lli ans= INT_MAX;
    while(l<=h){
        lli time= l + (h-l)/2;
        if(check(machine,noOfProducts,time)){
            ans= time;
            h= time-1;
        }
        else{
            l= time+1;
        }
    }
    c(ans);
    return 0;
}