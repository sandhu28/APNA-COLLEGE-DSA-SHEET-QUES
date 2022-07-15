#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define rep(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

vector<bool> checkArithmeticSubarrays(vector<int>& v, vector<int>& l, vector<int>& r) {
    
    int n= l.size();
    vector<bool> ans;
    for(int i=0;i<n;i++){
        int low= l[i];
        int high= r[i];
        vi temp(begin(v)+l[i],begin(v)+r[i]+1);
        sort(all(temp));
        int d = temp[1]-temp[0];
        for(int j=2;j<temp.size();j++){
            if(temp[j]-temp[j-1]!=d){
                ans.push_back(0);
                break;
            }
        }
        ans.push_back(1);
    }
    return ans;

}

int32_t main(){
    
    return 0;
}