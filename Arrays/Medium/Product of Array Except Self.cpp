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

vector<int> productExceptSelf(vector<int>& v) {
    int n= v.size();
    vi back(n);
    vi front(n);
    vi ans(n);
    back[n-1] = v[n-1]; front[0] = v[0];
    for(int i=n-2;i>=0;i--){
        back[i] = back[i-1]* v[i];
    }
    for(int i=1;i<n;i++){
        front[i] = front[i-1]* v[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            ans[i] = back[i+1];
        }
        else if(i==n-1){
            ans[i] = front[i-1];
        }
        else{
            ans[i] = front[i-1]* back[i+1];
        }
    }
    return ans;
}

int main(){
    
    return 0;
}