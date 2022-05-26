#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

// A little complex solution with more conditions required.
int minSubarray(vector<int>& v, int k) {
    int n= v.size();
    int ans= INT_MAX;
    vector<int> b_mod(n);
    int sm=0;
    for(int i=n-1;i>=0;i--){
        sm = ((sm%k)*1LL + ((v[i])%k)*1LL)%k;
        b_mod[i] = sm;
    }
    sm=0;
    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        sm = ((sm%k)*1LL + ((v[i])%k)*1LL)%k;
        int m= (sm%k + k)%k;
        if(m==0){ans= min(ans,n-i-1);}
        if(b_mod[i]==0){ans= min(ans,i);}
        int l_m= 0;
        if(i==n-1){
            continue;
        }
        else{
            l_m= b_mod[i+1];
        }
        int rem = k - l_m;
        if(um.find(rem)!=um.end()){
            ans = min(ans,i- um[rem]);
        }
        
        um[m] = i;
    }
    return ans==INT_MAX? -1:ans;
}

// Good neat and clean solution
int minSubarray(vector<int>& v, int k) {
    int n= v.size();
    int rem= 0;
    for(int i=0;i<n;i++){
        rem = ((rem%k)*1LL + (v[i]%k)*1LL)%k;
    }
    if(rem==0){return 0;}
    unordered_map<int,int> um={{0,-1}};
    int m=0;
    int ans= INT_MAX;
    for(int i=0;i<n;i++){
        m= (m%k + v[i]%k)%k;
        int find= (m- rem + k)%k;
        if(um.find(find)!= um.end()){
            ans= min(ans,i- um[find]);
        }
        um[m]= i;
    }
    if(ans== INT_MAX || ans== n){return -1;}
    return ans;

}
int main(){
    
    return 0;
}