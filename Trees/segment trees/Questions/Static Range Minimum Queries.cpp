// #include<iostream>
// #include<bits/stdc++.h>
// #define pii pair<int,int>
// #define lli long long int
// #define li long int
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vpii vector<pair<int,int>>
// #define vlli vector<lli>
// #define vli vector<li>
// #define all(x) (x).begin(),(x).end()
// #define rep(i,k,n) for (int i = k; i < n; ++i)
// #define Repr(i,k,n) for (int i = k; i >= n; --i)
// #define c(n) cout<<n<<endl
// #define z(n) cout<<n<<" "
// #define nl cout<<endl;
// #define INF INT_MAX
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// using namespace std;

// // const int M = 1e9 + 7;
// // const int N = 1e5+ 3;

// void build(int idx,vi &a,vi &seg,int l,int h){

//     if(l==h){
//         seg[idx]= a[l];
//         return;
//     }
//     int mid= l + (h-l)/2;
//     build(2*idx+1,a,seg,l,mid);
//     build(2*idx+2,a,seg,mid+1,h);
//     seg[idx]= min(seg[2*idx+1],seg[2*idx+2]);
// }

// int query(int idx,vi &a,vi &seg,int low,int high,int l,int r){
//     if(low>=l && high<= r){
//         return seg[idx];
//     }
//     if(low>r || high<l){
//         return INT_MAX;
//     }
//     int mid= low + (high-low)/2;
//     int left= query(2*idx+1,a,seg,low,mid,l,r);
//     int right= query(2*idx+2,a,seg,mid+1,high,l,r);
//     return min(left,right);
// }

// int main(){
//     fast_io;
//     int n;cin>>n;
//     int q;cin>>q;
//     vi a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     vi seg(4*n+5,INT_MAX);
//     build(0,a,seg,0,n-1);
//     // for(int i=0;i<4*n+2;i++){
//     //     z(i);c(seg[i]);
//     // }
//     while(q--){
//         int l,h;
//         cin>>l>>h;
//         c(query(0,a,seg,0,n-1,l-1,h-1));
//     }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
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

void build(vi &v, vi &seg, int idx, int l, int h)
{
    if (l == h)
    {
        seg[idx] = v[l];
        return;
    }
    int mid = l + (h - l) / 2;
    build(v, seg, 2 * idx + 1, l, mid);
    build(v, seg, 2 * idx + 2, mid + 1, h);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(vi &seg, int idx, int l, int h, int ql, int qh)
{
    if (l >= ql && h <= qh)
    {
        return seg[idx];
    }
    if ((h < ql) || (l > qh))
    {
        return INT_MAX;
    }
    int mid = l + (h - l) / 2;
    int left = query(seg, 2 * idx + 1, l, mid, ql, qh);
    int right = query(seg, 2 * idx + 2, mid + 1, h, ql, qh);
    return min(left, right);
}

int main()
{
    fast_io;
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi v(n);
    fo(i, n)
    {
        cin >> v[i];
    }
    vi seg(4 * n + 5, INT_MAX);
    int idx = 0;
    int l = 0, h = n-1;
    build(v, seg, idx, l, h);
    while (q--)
    {
        int ql,qh;
        cin>>ql>>qh;
        c(query(seg,idx,l,h,ql-1,qh-1));
    }

    return 0;
}