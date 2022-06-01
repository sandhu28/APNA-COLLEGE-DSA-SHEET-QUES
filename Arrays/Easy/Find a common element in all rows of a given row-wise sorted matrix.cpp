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

// Using arrays
int com_ele(vvi &v,int n,int m){
    int mn_row=0;
    int col[n];
    for(int i=0;i<n;i++){
        col[i] = m-1;
    }
    while(true){
        for(int i=0;i<n;i++){
            if(v[i][col[i]]<v[mn_row][col[mn_row]]){
                mn_row= i;
            }
        }
        int eq_ct=0;
        for(int i=0;i<n;i++){
            if(v[i][col[i]]>v[mn_row][col[mn_row]]){
                if(col[i]==0){
                    return -1;
                }
                col[i]--;
            }
            else{
                eq_ct++;
            }
        }
        if(eq_ct== n){
            return v[mn_row][col[mn_row]];
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vvi v(n,vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
        }
    }
    auto ans= com_ele(v,n,m);
    c(ans);
    return 0;
}