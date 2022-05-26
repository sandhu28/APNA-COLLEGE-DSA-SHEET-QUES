#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

void set_bit(vector<int> &v,int i){
    v[i >> 5] |= ( 1<< (i & 31));
}
bool check_bit(vector<int>& v, int i){
    return v[i >> 5] & (1<< (i & 31)) ;
}
void prt_all(int a,int b){
    int d= b-a;
    int sz= ceil((d*1.0)/32);
    vector<int> vec(sz);
    for(int i=a;i<=b;i++){
        if((i%2==0) || (i%5==0)){
            set_bit(vec,i-a);
        }
    }
    for(int j=a;j<=b;j++){
        if(check_bit(vec,j-a)){
            z(j);
        }
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    // prt_all(a,b);
    cout<<(-4)%3<<endl;
    return 0;
}