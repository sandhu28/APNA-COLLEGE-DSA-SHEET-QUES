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

// App : 1
void combi(vector<int>& num, int n, int i, vector<int>& com, int r,int idx ){
    if(com[r-1] != -1){
        for(auto &e: com){
            z(e);
        }
        nl;
        return;
    }
    while(n-i>= r-idx){
        com[idx]= num[i];
        combi(num,n,i+1,com,r,idx+1);
        while(i+1<n && num[i]==num[i+1]){
            i++;
        }
        i++;
    }
    com[idx]=-1;
    return;
}

void combi2(vector<int>& num, int n, int i, vector<int>& com, int r,int idx ){
    if(idx==r){
        for(auto &e: com){
            z(e);
        }
        nl;
        return;
    }
    if(i>=n){
        return;
    }
    com[idx] = num[i];
    combi2(num,n,i+1,com,r,idx+1);
    while(i+1<n && num[i]==num[i+1]){
        i++;
    }
    combi2(num,n,i+1,com,r,idx);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vi v(n);
    int i=0;
    rep(i,0,n){
        cin>>v[i];
    }
    int r;cin>>r;
    vi com(r,-1);
    sort(v.begin(),v.end());
    // combi(v,n,0,com,r,0);
    combi2(v,n,0,com,r,0);

    return 0;
}