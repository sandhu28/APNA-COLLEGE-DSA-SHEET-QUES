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
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

bool check(vi& v,lli mid, int k){
    lli noOfBlocks=1;
    int n= v.size(); lli sm=0;
    for(int i=0;i<n;i++){
        sm+= v[i];
        if(sm>mid){noOfBlocks++;sm= v[i];}
            
    }
    return noOfBlocks<=k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    lli l=*max_element(v.begin(),v.end());
    lli h= 1e18+10;
    lli ans=0;
    while(l<=h){
        lli mid= l + (h-l)/2;
        if(check(v,mid,k)){
            ans= mid;
            h= mid-1;
        }
        else{
            l= mid+1;
        }
    }
    c(ans);
    return 0;
}