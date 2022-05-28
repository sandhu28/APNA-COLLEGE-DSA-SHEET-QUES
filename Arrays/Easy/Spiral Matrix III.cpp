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

vector<vector<int>> spiralMatrixIII(int n, int m, int rst, int cst) {
    vector<vector<int>> ans;
    int steps= 1;
    int ct=1;
    int dir=1; // 1 means right and 0 means left
    ans.push_back({rst,cst});
    while(ct< m*n){
        if(dir){
            for(int j=cst+1;j<steps+cst+1;j++){
                if(ct==m*n){break;}
                if( (rst>=0 && rst<n)  && (j>=0 && j<m) ){
                    ans.push_back({rst,j});
                    ct++;
                }
               
            }
            cst= steps + cst;

            for(int i= rst+1;i<rst+1+ steps;i++){
                if(ct==m*n){break;}
                if((i>=0 && i<n) &&(cst>=0 && cst<m)){
                    ans.push_back({i,cst});
                    ct++;
                }
                
            }
            rst= rst+steps;
            steps++;
            dir ^= 1;
        }
        else{
            for(int j= cst-1;j>=cst- steps;j--){
                if(ct==m*n){break;}
                if((rst>=0 && rst<n)  && (j>=0 && j<m)){
                    ans.push_back({rst,j});
                    ct++;
                }
            }
            cst = cst-steps;
            for(int i= rst-1;i>= rst-steps;i--){
                if(ct==m*n){break;}
                if((i>=0 && i<n) &&(cst>=0 && cst<m)){
                    ans.push_back({i,cst});
                    ct++;
                }
            }
            rst= rst-steps;
            steps++;
            dir^=1;
        }
    }
    return ans;
}

int main(){
    
    auto ans=spiralMatrixIII(1, 4,0,0);
    return 0;
}