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

bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

    int n= s.size(),m= sub.size();
    bool arr[256][256];
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            arr[i][j] = 1;
        }
    }
    for(auto &map : mappings){
        arr[(int)map[0]][(int)map[1]] =1;
    }
    for(int i=0;i<n;i++){
        bool f=0;
        if((s[i] == sub[0]) || (arr[sub[0]][s[i]])){
            f=1;
        }
        if(f){
            int k= i+1;int j=1;
            while(((i<n) && (j<m)) && ((s[k]== sub[j]) || (arr[sub[j]][s[k]]))){
                i++;j++;
            }
            if(j==m){
                return 1;
            }
        }
    }
    return 0;       
}

int main(){
    
    return 0;
}