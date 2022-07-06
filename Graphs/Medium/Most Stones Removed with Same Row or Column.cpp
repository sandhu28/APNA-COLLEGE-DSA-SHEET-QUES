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

// const int M = 1e9 + 7;
const int N = 1e5+ 3;

// string find(string &s,map<string,string> &m){
//     if(m[s]==s){
//         return s;
//     }
//     return m[s] = find(m[s],m);
// }

// void Union(string &s1,string &s2,map<string,string> &m,int &ct,map<string,int> &sz){
//     string p1= find(s1,m);
//     string p2= find(s2,m);
//     if(p1!=p2){
//         if(sz[p1]<sz[p2]){
//             swap(p1,p2);
//         }
//         m[p2] = p1;
//         sz[p1] += sz[p2];
//         ct--;
//     }
// }

// int removeStones(vector<vector<int>>& stones) {
//     int n= stones.size();
//     // ans= n- (count)
//     // count== no of connected components
//     map<string,string> m;
//     map<string,int> sz;
//     int ct=n;
//     for(int i=0;i<n;i++){
//         string temp= "";
//         temp+= to_string(stones[i][0]) + " " + to_string(stones[i][1]);
//         m[temp]= temp;
//         sz[temp] =1;
//     }

//     for(auto &a: stones){
//         string s1= to_string(a[0]) + " " + to_string(a[1]);
//         for(auto &b: stones){
//             string s2= to_string(b[0]) + " " + to_string(b[1]);
//             if(a[0]==b[0] || a[1]== b[1]){
//                 Union(s1,s2,m,ct,sz);
//             }
//         }
//     }
//     return n-ct;

// }

int find(int i,vi &par){
    if(par[i]==i){
        return i;
    }
    return par[i]  = find(par[i],par);
}

void Union(int a,int b,vi &par,vi &sz){
    a= find(a,par);
    b= find(b,par);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        par[b]=a;
        sz[a]+= sz[b];
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n= stones.size();
    vi par(n,-1);  
    vi sz(n,0);
    for(int i=0;i<n;i++){
        par[i]=i;
        sz[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if((stones[i][0]== stones[k][0]) || (stones[i][1]==stones[k][1])){
                Union(i,k,par,sz);
            }
        }
    }
}

int main(){

    // string a= to_string(1) + " " + to_string(2);
    // string a= (1) + " " + (2);
    // c(a);
    
    return 0;
}