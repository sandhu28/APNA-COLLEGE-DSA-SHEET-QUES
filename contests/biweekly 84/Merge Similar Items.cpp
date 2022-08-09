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
#define vs vector<string>
#define ss second
#define ff first
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

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    vvi ans;
    int n= items1.size();
    int m= items2.size();
    vi arr(1003,0);
    vi arr2(1003,0);
    fo(i,m){
        arr[items2[i][0]]= items2[i][1];
        arr2[items1[i][0]]= items1[i][1];
    }
    fo(i,n){
        vi temp(2,0);
        int val= items1[i][0];
        temp[0]= val;
        temp[1] = items1[i][1] + arr[val];
        ans.push_back(temp);
    }
    fo(i,m){
        if(arr[items2[i][0]]==0){
            vi temp= {items2[i][0],items2[i][1]};
            ans.push_back(temp);
        }
    }
    sort(all(ans));
    return ans;

}



int main(){
    
    return 0;
}