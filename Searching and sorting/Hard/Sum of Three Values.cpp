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
    int n,x;cin>>n>>x;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[i]={x,i};
    }
    sort(v.begin(),v.end());
    bool possible= false;
    for(int i=0;i<n;i++){
        int num= x- v[i].first;
        if(num<0){continue;}
        int l=i+1;int h= n-1;bool found= false;
        while(l<h){
            if((v[l].first + v[h].first)==num){
                found = true;
                possible= true;
                z(v[i].second +1);z(v[l].second + 1);c(v[h].second+1);
                break;
            }
            else if((v[l].first + v[h].first)<num){
                l++;
            }
            else{
                h--;
            }
        }
        if(found){break;}
    }
    if(!possible){
        c("IMPOSSIBLE");
    }
    return 0;
}