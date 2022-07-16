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

    int t;cin>>t;
    while(t--){
        int n,c,q;
        cin>>n>>c>>q;
        string s;cin>>s;
        vpii v;
        v.push_back({1,s.size()});
        lli totLen= s.size();
        while(c--){
            lli kh=0;
            lli a,b;
            cin>>a>>b;
            lli l= b-a+1;
            for(int i=0;i<v.size();i++){
                lli cl= v[i].second- v[i].first+1;
                lli nkh = kh+ cl;
                if(nkh<a){kh=nkh;continue;}
                if(b<= kh){break;}
                if(a<kh+1){
                    if(b>nkh){
                        
                    }
                }
                if(v[i].second>=a){
                    v.push_back({a,v[i].second});
                    a= v[i].second+1;
                    l= l- (v[i].second-a+1);
                    if(l==0){break;}
                }
            }
        }


    }
    
    return 0;
}