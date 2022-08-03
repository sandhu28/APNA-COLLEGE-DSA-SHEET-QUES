#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

bool odd(int n){
    return n&1;
}

bool even(int n){
    return n%2==0;
}


pair <lli,lli> func(vlli v,int l, int r){    // {rem,cost}
    int n= v.size();
    if(l==r){
        return {-v[l]%M,0};
    }
    if(r-l+1==2){
        return {-1,(v[l-1]*v[l]*v[r]*v[r+1])};
    }
    // int ans = -1;
    lli mx = -1;
    lli rem = -1;
    for(int i = l;i<r;i++){
        // if((i-l+1)&1){
        //     // pair<lli,lli> left = func(v,l,i);
        //     // pair <lli,lli> right = func(v,i+1,r);
        //     // int cost= (left.first*right.first);
        //     // mx = max(mx, left.second + right.second + cost==1?0:cost);
        // }
        pair<lli,lli> left = func(v,l,i);
        pair <lli,lli> right = func(v,i+1,r);
        int cost= (left.first*right.first);
        int potential_cost = left.second + right.second + (cost==1?0:cost);
        // mx = max(mx, left.second + right.second + (cost==1?0:cost));
        if(potential_cost > mx){
            mx = potential_cost;
            if(odd(l-i+1) && odd(r-l+1-i)){
                rem = -1;
            }
            else if(odd(l-i+1) && even(r-l+1-i)){
                rem = left.first;
            }
            else if(even(l-i+1) && odd(r-l+1-i)){
                rem = right.first;
            }
            else{
                rem = -1;
            }
        }

        // else{
        //     pair<lli,lli> left = func(v,l,i);
        //     pair <lli,lli> right = func(v,i+1,r);
        //     mx = max(mx, left.second + right.second );
            
        // }
    }
    if(even(r-l+1)) return {-1,mx};
    else return {-rem,mx};
}

int main(){
    fast_io;
    int n;cin>>n;
    vlli v(n+2,1) ;
    foe(i,1,n+1){
        cin>>v[i];
    }
    // v.push_back(1);
    c(func(v,1,n).second);
    
    return 0;
}