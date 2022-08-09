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

int longestIdealString(string s, int k) {
        vector<int> mx(26,0);
        mx[s[0]-'a']= 1;
        int n= s.size();
        int ans= 1;
        for(int i=1;i<n;i++){
            int curr= s[i]-'a';
            int temp= 1;
            for(int j=0;j<26;j++){
                if(mx[j]==0){
                    continue;
                }
                if(abs(curr-j)<=k){
                    temp= max(temp,mx[j]+1);  
                }   
            }
            mx[curr]= temp;
            ans= max(ans,temp);
        }
        return ans;
    }

int main(){
    
    return 0;
}