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

int main(){
    fast_io;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vi ans(n);int idx=0;
        for(int i=0;i<n;i++){
            int num= v[i];
            int moves;cin>>moves;
            string s;cin>>s;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='D'){
                    if(num==9){
                        num=0;
                    }
                    else{
                        num+=1;
                    }
                }
                else{
                    if(num==0){
                        num=9;
                    }
                    else{
                        num-=1;
                    }
                }
            }
            ans[idx]= num;
            idx++;
        }
        for(int i=0;i<n;i++){
            z(ans[i]);
        }
        nl;
    }
    
    return 0;
}