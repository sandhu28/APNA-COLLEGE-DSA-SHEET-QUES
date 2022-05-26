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

int maxArea(vector<int>& heights) {
    int n= heights.size();
    int mx= INT_MIN;
    int l= 0;int h= n-1;
    while(l<h){
        int width = h- l;
        int hgt= min(heights[l],heights[h]);
        mx= max(mx, width*hgt);
        if(heights[l]<= heights[h]){
            l++;
        }
        else{
            h--;
        }
    }
    return mx;
}

int main(){
    
    return 0;
}