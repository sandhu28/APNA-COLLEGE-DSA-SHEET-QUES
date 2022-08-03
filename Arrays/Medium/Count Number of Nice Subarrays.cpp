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

int numberOfSubarrays(vector<int>& nums, int k) {
    int n= nums.size();
    vi v= nums;
    fo(i,n){
        if(v[i]&1){
            v[i]=1;
        }
        else{
            v[i]=0;
        }
    }
    vi pre(n,0);
    pre[0]= v[0];
    for(int i=1;i<n;i++){
        pre[i]= v[i]+ pre[i-1];
    }
    map<int,int> m;
    m[0]=-1;
    int ans=0;
    fo(i,n){
        if(pre[i]>=k){
            int rem= pre[i]-k;
            int idx= m[rem];
            ans+= idx+2;
        }
        m[pre[i]]=i;
    }
    return ans;

}
int numberOfSubarrays(vector<int>& nums, int k) {
    int n= nums.size();
    int ans=0;

    int i=0,j=0;
    int odd=0;
    while(j<n){
        odd+= (nums[i]%2);
        if(odd<k){
            j++;
        }
        bool f=0;
        while(nums[i]%2==0){
            f=1;
            ans+= (n-j);
            i++;
        }
        if(!f){ans+= 1;}
        j++;
    }


    return ans;

}

int main(){
    
    return 0;
}