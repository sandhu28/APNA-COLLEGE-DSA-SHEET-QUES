#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define vs vector<string>
#define ss second
#define ff first
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

int numSubarraysWithSum(vector<int>& v, int k) {
    int n= v.size();
    unordered_map<int,int> m;
    m[0]=1;
    int sm=0;int ans=0;
    fo(i,n){
        sm+= v[i];
        if(m.find(sm-k)!=m.end()){
            ans+= m[sm-k];
        }
        m[sm]++;
    }
    return ans;
}

int main(){
    
    return 0;
}