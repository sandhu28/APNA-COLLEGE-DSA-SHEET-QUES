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

int findMinArrowShots(vector<vector<int>>& v) {
    sort(all(v),[](vi &a,vi &b){
        if(a[1]==b[1]){
            return a[0]<=b[0];
        }
        return a[1]<b[1];
    });
    vi temp;
    int ct=1;
    temp.push_back(v[0][1]);
    for(int i=1;i<v.size();i++){
        auto it= lower_bound(all(temp),v[i][0]);
        if(it==temp.end()){
            ct++;
            temp.push_back(v[i][1]);
        }
    }
    return ct;
}

int main(){
    
    return 0;
}