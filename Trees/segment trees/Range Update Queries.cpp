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


void build(int idx,vi &a,vlli &seg,int l,int h){

    if(l==h){
        seg[idx]= a[l];
        return;
    }
    int mid= l + (h-l)/2;
    build(2*idx+1,a,seg,l,mid);
    build(2*idx+2,a,seg,mid+1,h);
    seg[idx]= (1LL*seg[2*idx+1]+ 1LL*seg[2*idx+2]);
}

void update(int u,int v,vlli &lazy,vi &a,vlli &seg,int idx,int l,int h,int val){
    if(lazy[idx]!=0){
        seg[idx] += (h-l+1)*1LL*lazy[idx];
        if(l!=h){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx]=0;
    }
    if(l>=u && h<=v){
        seg[idx] += (h-l+1)*1LL*val;
        if(l!=h){
            lazy[2*idx+1]+= val;
            lazy[2*idx+2]+= val;
        }
        return ;
    }
    if(h<u || l>v || l>h){return ;}
    int mid= l + (h-l)/2;
    update(u,v,lazy,a,seg,2*idx+1,l,mid,val);
    update(u,v,lazy,a,seg,2*idx+2,mid+1,h,val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    // return seg[idx];
}

lli printAns(int idx,int l,int h,int node,vlli &lazy,vi &a,vlli &seg){
    if(lazy[idx]!=0){
        seg[idx] += (h-l+1)*1LL*lazy[idx];
        if(l!=h){
            lazy[2*idx+1]+= lazy[idx];
            lazy[2*idx+2]+= lazy[idx];
        }
        lazy[idx]=0;
    }
    if(l==h){
        return seg[idx];
    }
    int mid= l + (h-l)/2;
    if(node<=mid && node>=l){
        return printAns(2*idx+1,l,mid,node,lazy,a,seg);
    }
    return printAns(2*idx+2,mid+1,h,node,lazy,a,seg);
}
int main(){
    fast_io;
    int n;cin>>n;
    int q;cin>>q;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vlli seg(4*n+5,0);
    build(0,a,seg,0,n-1);
    // for(int i=0;i<4*n+2;i++){
    //     z(i);c(seg[i]);
    // }
    vlli lazy(4*n+5,0);
    while (q--)
    {
        int check;
        cin>>check;
        if(check==1){
            int u,v,rep;
            cin>>u>>v>>rep;
            // update(0,a,seg,l-1,h,0,n-1);
            update(u-1,v-1,lazy,a,seg,0,0,n-1,rep);
        }
        else{
            int idx;cin>>idx;
            // c(query(0, a, seg, 0, n - 1, l - 1, h - 1));
            c(printAns(0,0,n-1,idx-1,lazy,a,seg));
        }
        
    }
    
    return 0;
}