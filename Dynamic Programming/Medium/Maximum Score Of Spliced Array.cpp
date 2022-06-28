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

int kadanes(vi &n1,vi &n2){
    int n= n1.size();
    int sm=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        sm+= n1[i] - n2[i];
        mx= max(mx,sm);
        if(sm<0){
            sm=0;
        }
    }
    return mx;
}
// int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    
//     int sm1= accumulate(all(nums1),0);
//     int sm2= accumulate(all(nums2),0);
//     return max(sm1 + kadanes(nums2,nums1), sm2 + kadanes(nums1,nums2));

// }

int main(){
    
    return 0;
}