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

// ques given two arr A, B of max size 1e5
// We create an array C of size |A| * |B| 
// containing or or each pair of A and B 
// Now we take Xor of all values of arr
// C find the resultant
bool Set(int num ,int pos){
    return (num)&(1<<pos);
}

int finalVal(vi &v1,vi &v2, int n,int m){
    int ans= 0;
    for(int i=0;i<32;i++){
        lli total_ones=0;
        int a_mein_0 =0;
        for(int a=0;a<n;a++){
            if(Set(v1[a],i)){
                total_ones+= m;
            }
            else{
                a_mein_0+=1;
            }
        }
        for(int b=0;b<m;b++){
            if(Set(v2[b],i)){
                total_ones+= a_mein_0;;
            }
        }
        if(total_ones &1){
            ans |= (1<<i);
        }
    }
    return ans;
}

int main(){

    int n,m;cin>>n>>m;
    vi v1(n);
    vi v2(m);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
    c(finalVal(v1,v2,n,m));
    
    return 0;
}