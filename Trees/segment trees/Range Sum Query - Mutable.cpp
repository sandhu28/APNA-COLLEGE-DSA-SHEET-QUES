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
class NumArray {
    private:
    vector<int> a;
    vector<int> seg;
    int sz;
public:
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        sz=n;
        // vector<int> v1(n+5,0);
        vector<int> seg1(4*n+5,0);
        a= nums;
        seg= seg1;
        build(0,0,n-1);
        // for(int i=0;i<=4*n;i++){
        //     cout<<seg[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
    }
    
    void update(int index, int val) {
        upd(0,0,sz-1,val,index);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,sz-1,left,right);
    }
    void build(int idx,int l,int h){
        // cout<<"yes"<<endl;

    if(l==h){
        seg[idx]= a[l];
        return ;
    }

    int mid= (l)+ (h-l)/2;
    build(2*idx + 1,l,mid);
    build(2*idx+2,mid+1,h);
    seg[idx]= (seg[2*idx+1]+seg[2*idx+2]);
}
    int query(int idx,int low,int high,int l,int r){
    // l and r denote the query
    if(low>=l && high<=r){
        return seg[idx];
    }
    if(high<l || low>r){
        return 0;
    }
    int mid= low + (high-low)/2;
    int left= query(2*idx+1,low,mid,l,r);
    int right= query(2*idx+2,mid+1,high,l,r);
    return (left+right);
}
    void upd(int idx,int l,int h,int val,int node){
        if(l==h){
            seg[idx]= val;
            return;
        }
        else{
            int mid= l+ (h-l)/2;
            if(node>=l && node<=mid){upd(2*idx+1,l,mid,val,node);}
            else{
                upd(2*idx+2,mid+1,h,val,node);
            }
            seg[idx]= seg[2*idx+1] + seg[2*idx+2];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main()
{

    return 0;
}