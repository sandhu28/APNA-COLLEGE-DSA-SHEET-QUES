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
    int n, k;
    cin >> n >> k;
    int temp=k;
    vector<pii> movies(n);
    for (int i = 0; i < n; i++)
    {
        int x,y;cin>>x>>y;
        movies[i]= {x,y};
    }    
    sort(movies.begin(),movies.end(),[](pii& pr1,pii& pr2){
        return pr1.second<pr2.second;
    });
    set<pii> s;
    int ct=0;
    for(int i=0;i<n;i++){
        if(s.empty()){
            s.insert({-movies[i].second,k});
            k--;
            continue;
        }
        auto pr= movies[i];
        if(s.upper_bound({-pr.first,-1})!= s.end()){
            auto it= s.upper_bound({-pr.first,0});
            s.erase(it);
            s.insert({-pr.second,it->second});
        }
        else{
            if(k==0){
                ct++;
            }
            else{
                s.insert({-pr.second,k});
                k--;
            }
        }
    }
    c(n-ct);
    return 0;
}