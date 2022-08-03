#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n= nums1.size();
    vi vec(n,0);
    fo(i,n){
        vec[i]= nums1[i];
    }
    int M = 1e9 + 7;
    sort(all(vec));
    lli ans=0;
    int mxDiff= 0;
    fo(i,n){
        int a= nums1[i],b= nums2[i];
        int currDiff= abs(a-b);
        // ans= (ans%M + currDiff%M)%M;
        ans+= 1LL*currDiff;
        if(currDiff==0){
            continue;
        }
        else{
            auto it= lower_bound(all(vec),b);
            int next= it==vec.end()?-1e6: *it;
            int prev= it==vec.begin()?-1e6: *(--it);
            int diff1= abs(next-b);
            int diff2= abs(prev-b);
            int temp= currDiff;
            if(diff1<currDiff){
                mxDiff= max(mxDiff,currDiff-diff1);
                temp= diff1;
            }
            if(diff2<temp){
                mxDiff= max(mxDiff,currDiff-diff2);
            }
        }
    }
    // ans= (ans%M- mxDiff%M)%M;
    ans= ans- 1LL*mxDiff;
    int k= ans%M;
    return k;
        
}

int main(){
    
    return 0;
}