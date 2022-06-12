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
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int recur(vi &cookies, vi& sm,int i,int n,int k){

    if(i== n){
        int ans= INT_MIN;
        for(int ch= 0;ch<k;ch++){
            ans= max(ans,sm[ch]);
        }
        return ans;
    }
    int ans= INT_MAX;
    for(int ch=0;ch<k;ch++){
        sm[ch]+= cookies[i];
        int curr= recur(cookies,sm,i+1,n,k);
        ans = min(ans,curr);
        sm[ch]-= cookies[i];
    }
    return ans;
}

int distributeCookies(vector<int>& cookies, int k) {
        
    int n= cookies.size();
    vi sm(k,0);
    return recur(cookies,sm,0,n,k);
}

int main(){
    
    return 0;
}