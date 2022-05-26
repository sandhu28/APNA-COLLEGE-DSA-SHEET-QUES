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


vector<vector<int>> threeSum(vector<int>& v) {
    int n= v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;
    int prev= INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]==prev){continue;}
        prev= v[i];
        int k= -1 * v[i];
        int l= i+1;int h= n-1;
        while(l<h){
            if(v[l]+ v[h] < k){
                l++;
            }
            else if(v[l]+ v[h] > k){
                h--;
            }
            else{
                vector<int> temp;
                temp.push_back(v[i]);
                temp.push_back(v[l]);
                temp.push_back(v[h]);
                ans.push_back(temp);
                while(l<h && v[l]==v[i+1]){l++;}
            }
        }
    }
    return ans;
}

int main(){
    
    return 0;
}