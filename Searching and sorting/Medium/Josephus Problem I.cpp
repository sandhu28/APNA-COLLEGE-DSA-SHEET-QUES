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
    vector<int> children(n);
    for(int i=0;i<n;i++){
        children[i]= i+1;
    }
    while(children.size()>1){
        vector<int> survived;
        int sz= children.size();
        for(int i=0;i<children.size();i++){
            if(i&1){
                z(children[i]);
            }
            else{
                survived.push_back(children[i]);
            }
        }
        if(!(sz&1)){
            children= survived;
        }
        else{
            children.clear();
            children.push_back(survived.back());
            survived.pop_back();
            for(auto &e: survived){
                children.push_back(e);
            }
        }

    }
    z(children[0]);
    
    return 0;
}