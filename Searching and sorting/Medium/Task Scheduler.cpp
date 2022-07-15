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

int leastInterval(vector<char>& v, int n) {
    vector<int> ct(26,0);
    int mx=0;
    int ctMx=0;
    for(int i=0;i<n;i++){
        ct[v[i]-'A']++;
        if(ct[v[i]-'A']==mx){
            ctMx++;
        }
        else if(ct[v[i]-'A']>mx){
            mx= ct[v[i]-'A'];
            ctMx=1;
        }
    }
    int parts= mx-1;
    int empty= parts*(n-(ctMx-1)); 
    int bacheHue= n- mx*ctMx;
    int idles= max(0,empty-bacheHue);
    return n+ idles;

}

int main(){
    
    // cout<<(char)(5+'A')<<endl;
    return 0;
}