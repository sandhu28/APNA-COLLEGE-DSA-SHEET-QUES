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


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int dfs(map<int,pair<int,vi>> &m,int id,int &ans){
        ans+= m[id].first;
        for(auto &child: m[id].second){
            dfs(m,child,ans);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n= employees.size();
        // vi impor(n+1);
        // vvi g(n+1);
        map<int,pair<int,vi>> m;
        for(auto &pr: employees){
            m[pr->id]= {pr->importance,pr->subordinates};
        }
        int ans=0;
        dfs(m,id,ans);
        return ans;
        
        
    }
};

int main(){


    
    return 0;
}