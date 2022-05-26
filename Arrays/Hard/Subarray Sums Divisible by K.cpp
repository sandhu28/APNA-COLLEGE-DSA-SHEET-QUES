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

int subarraysDivByK(vector<int>& arr, int k) {
    int n= arr.size();
    int sm=0;
    unordered_map<int,int> um;
    int ans= 0;
    for(int i=0;i<n;i++){
        sm+= arr[i];
        int m= (sm%k + k)%k;
        if(m==0){
           ans++;
        }
        if(um.find(m)!=um.end()){
            ans+= um[m];
        }
        um[m]++;
    }
    return ans;
}

int main(){
    
    return 0;
}