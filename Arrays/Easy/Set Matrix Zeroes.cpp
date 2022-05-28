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

// Used a lot of extra space here
void setZeroes(vector<vector<int>>& matrix) {
    int n= matrix.size();
    int m= matrix[0].size();
    unordered_map<int,int> um;
    rep(i,0,n){
        rep(j,0,m){
            if(matrix[i][j]==0){
                um.insert({i,j});
            }
        }
    }
    vector<bool> row(n,1);
    vector<bool> col(m,1);
    for(auto &pr: um){
        int r=pr.first,c= pr.second;
        if(row[r]){
            for(int j=0;j<m;j++){
                matrix[r][j]=0;
            }
        }
        if(col[c]){
            for(int i=0;i<n;i++){
                matrix[i][c]=0;
            }
        }
        row[r]=0;
        col[c]=0;
    }

}

// O(1) space solution
void setZeroes(vector<vector<int>>& matrix) {
    int n= matrix.size();
    int m= matrix[0].size();
    bool col0=0; // 1 means 0 col mein 0 present hai
    rep(i,0,n){
        rep(j,0,m){
            if(j==0 && matrix[i][j]==0){col0=1;}
            if(matrix[i][j]==0){
                if(j!=0){
                    matrix[0][j]=0;
                }
                matrix[i][0]=0;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if((matrix[i][0]==0) || ((matrix[0][j]==0)&& j!=0)){
                matrix[i][j]=0;
            }
            if(col0 && j==0){
                matrix[i][0]=0;
            }
        }
    }  

}
int main(){
    
    return 0;
}