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
        for(auto &e: v){z('0');}
        return 0;
    }
    if(k==2){
        for(int i=1;i<n;i++){
            int median= min(v[i],v[i-1]);
            if(v[i]==median){
                z(v[i-1]-median);
            }
            else{
                z(v[i]-median);
            }
        }
        return 0;
    }
    vector<pii> temp;
    for(int i=0;i<k;i++){
        temp.push_back({v[i],i});
    }
    sort(temp.begin(),temp.end());
    int medi= temp[((k-1)/2)].first;
    lli cost=0;
    for(int i=0;i<k;i++){
        cost= cost + 1LL*abs(v[i]-medi);
    }
    z(cost);
    set<pii> ls;
    set<pii> rs;
    lli sumLeft=0,sumRight=0;
    for(int i=0;i<(k/2)+(k%2);i++){
        ls.insert(temp[i]);
        sumLeft+= temp[i].first;
    }
    for(int i=(k/2)+(k%2);i<k;i++){
        rs.insert(temp[i]);
        sumRight+= temp[i].first;
    }
    // z(sumLeft);c(sumRight);
    for(int j= k;j<n;j++){
        if(ls.find({v[j-k],j-k})!= ls.end()){
            ls.erase({v[j-k],j-k});
            sumLeft-= v[j-k];
        }
        else{
            rs.erase({v[j-k],j-k});
            sumRight -= v[j-k];
        }
        if(ls.rbegin()->first < v[j]){
            rs.insert({v[j],j});
            sumRight+= v[j];
        }
        else{
            ls.insert({v[j],j});
            sumLeft+= v[j];
        }
        while(ls.size()< (k/2)+(k%2)){
            auto pr= *rs.begin();
            ls.insert(pr);
            sumLeft+= pr.first;
            rs.erase(pr);
            sumRight-= pr.first;
        }
        while(rs.size()<(k/2)){
            auto pr= *ls.rbegin();
            rs.insert(pr);
            sumRight+= pr.first;
            ls.erase(pr);
            sumLeft-= pr.first;
        }
        int med= (ls.rbegin()->first);
        lli currCost = (med*1LL*(ls.size()) - 1LL*sumLeft) + (1LL*sumRight) - (1LL*rs.size()*med);
        z(currCost);
    }
    return 0;
}