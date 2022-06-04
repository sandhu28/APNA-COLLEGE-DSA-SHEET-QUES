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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if(k==1){
        for(auto &e: v){z(e);}
        return 0;
    }
    if(k==2){
        for(int i=1;i<n;i++){
            z(min(v[i],v[i-1]));
        }
        return 0;
    }
    vector<pii> temp;
    for(int i=0;i<k;i++){
        temp.push_back({v[i],i});
    }
    sort(temp.begin(),temp.end());
    cout<<temp[((k-1)/2)].first<<" ";
    set<pii> ls;
    set<pii> rs;
    for(int i=0;i<(k/2)+(k%2);i++){
        ls.insert(temp[i]);
    }
    for(int i=(k/2)+(k%2);i<k;i++){
        rs.insert(temp[i]);
    }
    for(int j= k;j<n;j++){
        if(ls.find({v[j-k],j-k})!= ls.end()){
            ls.erase({v[j-k],j-k});
        }
        else{
            rs.erase({v[j-k],j-k});
        }
        if(ls.rbegin()->first < v[j]){
            rs.insert({v[j],j});
        }
        else{
            ls.insert({v[j],j});
        }
        while(ls.size()< (k/2)+(k%2)){
            auto pr= *rs.begin();
            ls.insert(pr);
            rs.erase(pr);
        }
        while(rs.size()<(k/2)){
            auto pr= *ls.rbegin();
            rs.insert(pr);
            ls.erase(pr);
        }
        z(ls.rbegin()->first);
    }
    return 0;
}