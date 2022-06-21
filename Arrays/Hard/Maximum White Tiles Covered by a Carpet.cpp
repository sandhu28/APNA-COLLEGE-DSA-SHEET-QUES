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

int maximumWhiteTiles(vector<vector<int>>& t, int carpetLen) {

    int n= t.size();
    int ans=0,cover=0,j=0;
    sort(all(t));
    for(int i=0;ans< carpetLen && (i<n);){
        if(t[j][0] + carpetLen> t[i][1]){
            cover+= (t[i][1]- t[i][0] + 1);
            ans= max(ans,cover);
            ++i;
        }
        else{
            int partial= t[j][0] + carpetLen - t[i][0];
            ans= max(ans, cover+ partial);
            cover-= t[j][1] - t[j][0] + 1;
            ++j;
        }
    }
    return ans;
        
}

int maximumWhiteTiles(vector<vector<int>>& t, int carpetLen) {

    int n= t.size();
    sort(all(t));
    vlli prefix(n,0);
    vi end(n,0);
    end[0] = t[0][1];
    prefix[0]=t[0][1]- t[0][0] +1;
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + t[i][1]- t[i][0] + 1;
        end[i]= t[i][1];
    }
    int ans= INT_MIN;
    for(int i=0;i<n;i++){
        int st= t[i][0];
        int en= t[i][0] + carpetLen -1;
        int idx= upper_bound(all(end),en)- end.begin();
        // c(idx);
        int curr=0;
        if(i==0){
            if(idx!=0){
                curr+= prefix[idx-1];
                // c(curr);
            }
            
        }
        else{
            curr+= prefix[idx-1] - prefix[i-1];
        }
        if((idx<n) && (en>=t[idx][0])){
            curr+= en- t[idx][0] + 1;
        }
        ans= max(ans,curr);
    }
    return ans;

        
}
// [[8051,8057],[8074,8089],[7994,7995],[7969,7987],[8013,8020],[8123,8139],[7930,7950],[8096,8104],[7917,7925],[8027,8035],[8003,8011]]
// 9854

int main(){
    // c(1 && (-1));
    return 0;
}