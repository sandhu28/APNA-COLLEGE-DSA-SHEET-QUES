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

int longSubarrWthSumDivByK(int arr[], int n, int k)
{
	vector<int> m(n);
    int sm=0;
    for(int i=0;i<n;i++){
        sm+= arr[i];
        m[i]= (sm%k + k)%k;
    }
    unordered_map<int,int> um;
    int ans= INT_MIN;
    for(int i=0;i<n;i++){
        if(m[i]==0){
            ans= max(ans,i+1);
        }
        else if(um.find(m[i])!=um.end()){
            ans= max(ans,i - um[m[i]] + 1);
        }
        else{
            um[m[i]]= i;
        }
    }
    return ans;

}
int main(){
    
    return 0;
}