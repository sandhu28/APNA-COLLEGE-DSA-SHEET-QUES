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

int countSubstrings(string s)
{
    int ans= 0;
    int n = s.size();
    if (n == 1)
    {
        return 1;
    }
    bool arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    int st = 0;
    int en = 0;
    int mx = INT_MIN;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g==0)
            {
                arr[i][j] = 1;ans++;
                st = i;
                en = i;
                mx=1;
                continue;
            }
            if(g==1){
                if(s[i]==s[j]){
                    ans++;
                    mx= max(mx,2);
                    st = i;
                    en = j;
                    arr[i][j]=1;
                }
            }
            
            else
            {
                if (s[i] == s[j])
                {
                    if(arr[i+1][j-1]==1){
                        ans++;
                        mx= max(mx,j-i+1);
                        st = i;
                        en = j;
                        arr[i][j]=1;
                    }   
                    
                }
              
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}