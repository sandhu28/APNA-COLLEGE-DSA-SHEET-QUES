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

vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {

    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    int n= v.size();
    int mn= v[0][0];int mx= v[0][1];
    for(int i=1;i<n;i++){
        int cmn= v[i][0];
        int cmx= v[i][1];
        if(cmn<=mx){
            mx= max(cmx,mx);
        }
        else{
            vi temp= {mn,mx};
            ans.push_back(temp);
            mn= cmn;
            mx= cmx;
        }
    }
    vi temp= {mn,mx};
    ans.push_back(temp);
    return ans;
}

int main(){
    
    return 0;
}