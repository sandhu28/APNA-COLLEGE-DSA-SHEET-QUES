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
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int> us;
    int st=0;int en=0;
    int mx= INT_MIN;
    while(st<n && en<n){
        if(us.count(v[en])){
            while(st<= en && us.count(v[en])){
                us.erase(v[st]);
                st++;
            }
            us.insert(v[en]);
            en++;
        }
        else{
            us.insert(v[en]);
            mx= max(mx,en-st+1);
            en++;
        }
    }
    c(mx);
    return 0;
}

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;cin>>n;
//     vi v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     unordered_map<int,int> um;
//     int st=0;int en=0;
//     int mx= 0;
//     while(st<= en && en<n){
//         if(um.find(v[en])!=um.end()){
//             if(um[v[en]]>=st){
//                 st= um[v[en]]+1;
//             }
//         }
//         else{
//             mx= max(mx,en-st+1);
//         }
//         um[v[en]]=en;
//         en++;
//     }
//     c(mx);
//     return 0;
// }