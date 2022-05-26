#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

string longestCommonPrefix(vector<string> &v)
{

    int n = v.size();
    string ans="";
    bool t= true;
    for (int idx = 0; idx < 200; idx++)
    {
       
        char ch;
        for (int i = 0; i < n; i++){
            if(i==0){
                if(v[0].size()<idx+1){
                    t=false;
                    break;
                }
                ch= v[i][idx];
            }
            else{
                if(v[i].size()<idx+1 || v[i][idx]!= ch){
                    t= false;
                    break;
                }
            }
        }
         if(!t){
            break;
        }
        ans+= ch;
    }
    return ans;
}
int main()
{

    return 0;
}