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

int main(){
    fast_io;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n);
        fo(i,n){
            cin>>v[i];
        }
        int a= v[0];
        bool f=1;
        for(int i=1;i<n;i++){
            if(v[i]%a!=0){
                f=0;
                break;
            }
        }
        if(f){c("yes");}
        else{
            c("no");
        }
    }
    

    
    return 0;
}