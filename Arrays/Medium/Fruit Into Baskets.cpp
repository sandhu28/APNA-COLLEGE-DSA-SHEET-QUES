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

int totalFruit(vector<int>& v) {
    int n= v.size();
    unordered_map<int,int> m;
    int i=0,j=0;
    int ans=0;
    while(j<n){
        m[v[j]]++;
        if(m.size()>2){
            ans+= j-i;
            while(i<n && m.size()>2){
                m[v[i]]--;
                if(m[v[i]]==0){
                    m.erase(v[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}

int totalFruit(vector<int>& v) {
    int n= v.size();
    int lf=-1,lfCt=0,slf= -1,curr=0,mx= 0;
    fo(i,n){
        if(v[i]== lf || v[i]== slf){
            curr++;
        }
        else{
            curr= lfCt+1;
        }
        if(v[i]==lf){
            lfCt++;
        }
        else{
            lfCt=1;
        }
        if(v[i]!=lf){
            slf= lf;
            lf= v[i];
        }
        mx= max(curr,mx);
    }

    return mx;
}

int main(){
    
    return 0;
}