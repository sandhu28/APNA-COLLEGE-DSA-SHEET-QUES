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

bool isValid(int mid,vi &v,int mx){
    int op=0;
    int n= v.size();
    for(int i=0;i<n;i++){
        if(v[i]> mid){
            int k= v[i]/mid;
            if(v[i]%mid==0){
                op+= k-1;
            }
            else{
                op+= k;
            }
        }
    }
    return op<= mx;
}

int minimumSize(vector<int>& v, int mx) {
    int n= v.size();
    int l=1;int h= 1e9;
    int ans= INT_MAX;
    while(l<=h){
        int mid= l + (h-l)/2;
        if(isValid(mid,v,mx)){
            ans= mid;
            h= mid-1;
        }
        else{
            l= mid+1;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}