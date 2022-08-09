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
const int N = 1e5+ 5;
int a[N],seg[4*N];

void build(int idx,int l,int h){

    if(l==h){
        seg[idx]= a[l];
        return ;
    }

    int mid= (l)+ (h-l)/2;
    build(2*idx + 1,l,mid);
    build(2*idx+2,mid+1,h);
    seg[idx]= max(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx,int low,int high,int l,int r){
    // l and r denote the query
    if(low>=l && high<=r){
        return seg[idx];
    }
    if(high<l || low>r){
        return INT_MIN;
    }
    int mid= low + (high-low)/2;
    int left= query(2*idx+1,low,mid,l,r);
    int right= query(2*idx+2,mid+1,high,l,r);
    return max(left,right);
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        c(query(0,0,n-1,l,r));
    }
    
    return 0;
}