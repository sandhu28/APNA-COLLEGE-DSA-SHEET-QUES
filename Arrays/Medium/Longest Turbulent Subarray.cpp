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
int maxTurbulenceSize(vector<int>& arr) {
    int n= arr.size();
    if(n==1){
        return 1;
    }
    if(n==2){
        if(arr[0]==arr[1]){return 1;}
        else{return 2;}
    }
    
    int sz=0;int mx_sz=INT_MIN;int sign=0;// 0 -ve and 1 +ve
    if(arr[0]==arr[1]){
        sz=-1;
        sign = -1;
    }
    else{
        if(arr[0]>arr[1]){sz=2;sign = 0; }
        else{sz=2;sign=1;}
    }
    for(int i=2;i<n;i++){
        int d = arr[i]-arr[i-1];
        int curr_sign= d>0?1:0;
        if(d==0){sz=-1;sign=-1;}
        else if(sign==-1){
            sz= 2;sign = curr_sign;
        }
        else{
            if(curr_sign==sign){
                sz= 2; 
                sign= curr_sign;
            }
            else{
                sz+= 1;
                sign = sign ^ 1;
            }
        }
        mx_sz= max(mx_sz,sz);
    }
    return mx_sz>0?mx_sz:1;
}

int main(){
    
    return 0;
}