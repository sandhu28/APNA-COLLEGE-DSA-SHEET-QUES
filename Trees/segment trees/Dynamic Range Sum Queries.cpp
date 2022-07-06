#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(), (x).end()
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

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

lli query(int idx,vi &a,vlli &seg,int low,int high,int l,int r){
    if(low>=l && high<= r){
        return seg[idx];
    }
    if(low>r || high<l){
        return 0;
    }
    int mid= low + (high-low)/2;
    lli left= query(2*idx+1,a,seg,low,mid,l,r);
    lli right= query(2*idx+2,a,seg,mid+1,high,l,r);
    return (1LL*left + 1LL*right);
}

void update(int idx,vi &a,vlli &seg,int updIdx,int val,int l,int h){
    if(l==h){
        seg[idx]= val;
        return;
    }
    int mid= l + (h-l)/2;
    if(updIdx>= l && updIdx<=mid ){
        update(2*idx+1,a,seg,updIdx,val,l,mid);
    }
    else{
        update(2*idx+2,a,seg,updIdx,val,mid+1,h);
    }
    seg[idx] = 1LL*seg[2*idx+1] + seg[2*idx+2];
}

int main()
{
    fast_io;
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vlli seg(4 * n + 5, 0);
    build(0, a, seg, 0, n - 1);
    // for(int i=0;i<4*n+4;i++){
    //     z(i);c(seg[i]);
    // }
    while (q--)
    {
        int check,l, h;
        cin >>check >> l >> h;
        if(check==1){
            update(0,a,seg,l-1,h,0,n-1);
            continue;
        }
        c(query(0, a, seg, 0, n - 1, l - 1, h - 1));
    }
    // c("hello");
    return 0;
}