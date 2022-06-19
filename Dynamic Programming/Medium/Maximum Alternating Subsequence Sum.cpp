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
// 0 matlab even pe daalne ja raha 
// 1 matlab odd pe daalne ja raha hun.
// vector<vlli> memo(N,vlli(2,-1));
lli rec(vi &v,bool f,int i,vector<vlli> &memo){
    if(i== v.size()){
        return 0;
    }
    if(memo[i][f]!=-1){
        return memo[i][f];
    }
    lli ans=0;
    if(f==0){
        ans = rec(v,f^1,i+1,memo) + v[i];
    }
    else{
        ans = rec(v,f^1,i+1,memo) - v[i];
    }
    ans= max(ans,rec(v,f,i+1,memo));
    return memo[i][f]= ans;
}


lli dpTable(vi& v){
    int n= v.size();
    vlli evenSum(n,0);
    vlli oddSum(n,0);
    evenSum[0] = v[0];
    for(int i=1;i<n;i++){
        evenSum[i] = max(evenSum[i-1],oddSum[i-1] + 1LL*v[i]);
        oddSum[i] = max(oddSum[i-1], evenSum[i-1] - 1LL*v[i]);
    }
    return max(evenSum[n-1],oddSum[n-1]);
}


lli dpTable(vi& v){
    int n= v.size();
    // vlli evenSum(n,0);
    // vlli oddSum(n,0);
    lli evenSum= v[0];
    lli oddSum= 0;
    // evenSum[0] = v[0];
    for(int i=1;i<n;i++){
        evenSum = max(evenSum,oddSum + 1LL*v[i]);
        oddSum = max(oddSum, evenSum - 1LL*v[i]);
    }
    return max(evenSum,oddSum);

}

// Wrong logic
// long long maxAlternatingSum(vector<int>& nums) {
//     int n= nums.size();
//     multiset<lli> s1; // odd no of val
//     multiset<lli> s2; // even no of val
//     // vpii v(n);
//     // 1-> means odd // 0-> means even
//     // v[0] = {nums[0],1};
//     s1.insert(nums[0]);
//     lli ans= nums[0];
//     for(int i=1;i<n;i++){
//         lli os = *s1.rbegin();
//         auto it= s2.rbegin();
//         lli es= 0;
//         if(!s2.empty()){
//             es= *it;
//         }
//         lli v1 = os -  1LL*nums[i]; // even val hogai
//         lli v2= es + 1LL*nums[i]; // odd val hogai
//         if(v1 > v2){
//             s2.insert(v1);
//             ans= max(ans,v1);
//         }
//         else if (v2> v1){
//             s1.insert(v2);
//             ans= max(ans,v2);
//         }
//         else{
//             s2.insert(v1);
//             ans= max(ans,v1);
//         }
//     }
//     return ans;

// }

int main(){
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vlli> memo(n,vlli(2,-1));
    lli ans =rec(v,0,0,memo);
    c(ans);

    
    return 0;
}
