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


int trap(vector<int>& h) {
    int ans=0;
    int n= h.size();
    vi back(n);vi front(n);
    back[n-1]= h[n-1];
    front[0]= h[0];
    for(int i=n-2;i>0;i--){
        back[i]= max(back[i+1],h[i]);
    }
    for(int i=1;i<n;i++){
        front[i] = max(front[i-1],h[i]);
    }
    for(int i=1;i<n-1;i++){
        int mn=  min(front[i-1],back[i+1]);
        if(mn>h[i]){
            ans += mn- h[i];
        }
    }
    return ans;
}

int main(){
    
    return 0;
}