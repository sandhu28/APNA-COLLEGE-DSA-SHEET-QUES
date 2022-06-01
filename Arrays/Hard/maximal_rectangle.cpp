#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int largestRectangleArea(vector<int>& h) {
    int n= h.size();
    vector<int> nsl,nsr;
    stack<int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && (h[stk.top()]>=h[i])){
            stk.pop();
        }
        if(stk.empty()){
            nsl.push_back(-1);
        }
        else{
            nsl.push_back(stk.top());
        }
        stk.push(i);
    }
    while(!stk.empty()){stk.pop();}
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && (h[stk.top()]>=h[i])){
            stk.pop();
        }
        if(stk.empty()){
            nsr.push_back(n);
        }
        else{
            nsr.push_back(stk.top());
        }
        stk.push(i);
    }
    reverse(nsr.begin(),nsr.end());
    int mx= INT_MIN;
    for(int i=0;i<n;i++){
        // cout<<i<<" "<<h[i]<<" "<<nsr[i]-nsl[i]-1<<endl;
        mx = max(mx, h[i]*(nsr[i]-nsl[i]-1));
    }
    return mx;
}
int main(){
    
    return 0;
}