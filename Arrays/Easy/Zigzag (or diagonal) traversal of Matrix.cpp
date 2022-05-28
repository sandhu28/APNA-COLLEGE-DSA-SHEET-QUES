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

void zigzag(vvi &v){
    int n= v.size();
    int m= v[0].size();
    for(int i=0;i<n;i++){
        int j=0;
        int temp=i;
        while(temp>=0){
            z(v[temp][j]);
            temp--;j++;
        }
        nl;
    }
    for(int j=1;j<m;j++){
        int i=n-1;
        int temp=j;
        while(temp< m){
            z(v[i][temp]);
            i--;temp++;
        }
        nl;
    }
}
int main(){
    int n;int m;
    cin>>n;cin>>m;
    vvi v(n,vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
        }
    }
    zigzag(v);
    return 0;
}