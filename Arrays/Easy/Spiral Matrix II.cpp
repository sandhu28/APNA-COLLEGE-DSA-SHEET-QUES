#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n*n);
    int k=1;
    int rst=0;int ren= n-1;int cst=0;int cen = n-1;
    while(rst<= ren && cst<=cen){

        for(int j= cst;j<=cen;j++){
            ans[rst][j]= k;
            k++;
        }
        rst++;

        for(int i=rst;i<=ren;i++){
            ans[i][cen]= k;
            k++;
        }
        cen--;

        for(int j=cen;j>=cst;j--){
            ans[ren][j] = k;
            k++;
        }
        ren--;

        for(int i=ren;i>=rst;i--){
            ans[i][cst] = k;
            k++;
        }
        cst++;
    }
    return ans;
}

int main(){
    
    return 0;
}