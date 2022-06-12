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

double calculateTax(vector<vector<int>>& brackets, int income) {
    int n= brackets.size();
    vi v;
    v.push_back(brackets[0][1]);
    for(int i=1;i<n;i++){
        v.push_back(brackets[i][0] - brackets[i-1][0]);
    }  
    double ans=0.0;
    for(int i=0;i<v.size();i++){
        int no = v[i];
        if(income< brackets[i][1]){
            brackets[i][1]= income;
        }
        ans = ans + (((1.0)*(double)brackets[i][1])*no)/((double)100);
        income-= brackets[i][1];
    }
    return ans;
}

int main(){
    
    return 0;
}