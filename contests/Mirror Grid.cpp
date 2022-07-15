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
#define fo(i,n) for(int i=0;i<n;i++)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

// 2,2-> 2,3 -> 3,3 -> 3,2
// 3,2 -> 2,2 -> 2,3 -> 3,3
// 1,4-> 4,4 -> 4,1 -> 1,1
// i,j -> j,n-i+1 -> n-i+1,n-j+1 -> n-j+1, i
// 0,3 -> 3,3 -> 3,0 -> 0,0
// i,j -> j,n-i-1 -> n-i-1,n-j-1 -> n-j-1,i


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vvi v(n,vi(n));
        fo(i,n){
            fo(j,n){
                char ch;
                cin>>ch;
                v[i][j]= ch-'0';
            }
        }
        lli ans=0;
        fo(i,n){
            fo(j,n){
                int ct1=0;
                int ct0=0;
                v[i][j]==1? ct1+=1: ct0+=1;
                v[j][n-i-1]==1? ct1+=1: ct0+=1;
                v[n-i-1][n-j-1]==1? ct1+=1: ct0+=1;
                v[n-j-1][i]==1? ct1+=1: ct0+=1;
                ans+= 1LL*min(ct1,ct0);
            }
        }
        c(ans/(4*1LL));
    }
    
    return 0;
}