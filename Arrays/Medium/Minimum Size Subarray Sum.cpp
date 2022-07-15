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

int minSubArrayLen(int ts, vector<int>& v) {
    int n= v.size();
    int i=0,j=0;
    int sm=0;
    int mn= INT_MAX;
    while(j<n){
        sm+= v[j];
        if(sm>= ts){
            while(sm>=ts && (i<=j)){
                mn= min(mn,j-i+1);
                sm-= v[i];
                i++;
            }
        }
        j++;
    }
    return mn;
}

int main(){
    
    return 0;
}