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

int longestOnes(vector<int>& nums, int k) {
    int ct=k;
    int n= nums.size();
    int i=0,j=0;
    int ans=0;
    while(j<n){
        if(nums[j]==1){
            j++;
            ans= max(ans,j-i);
            continue;
        }
        if(ct>0){
            ct--;
            j++;
            ans= max(ans,j-i);
        }
        else{
            ans= max(ans,j-i);
            while(ct==0){
                if(nums[i]==1){
                    i++;
                    continue;
                }
                i++;
                ct++;
            }
        }
    }
    
    return ans;
}
int main(){
    
    return 0;
}