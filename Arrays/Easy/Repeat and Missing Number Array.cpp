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

// Memory limit exceeded error aea tha ismein
vector<int> repeatedNumber(const vector<int> &a) {
    unordered_map<int,int> um;
    int n= a.size();
    int mx= *max_element(a.begin(),a.end());
    int A=0;int B= 0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(um[a[i]]>0){
            A= a[i];
        }
        um[a[i]]++;
    }
    ans.push_back(A);
    for(int i=1;i<=mx;i++){
        if(um[i]==0){B=i;break;}
    }
    ans.push_back(B);
    return ans;
}

// Ismein sums calculate kie explicitly but sirf diff chahiye
vector<int> repeatedNumber(const vector<int> &a) {

    int n= a.size();
    lli s2=0;
    for(int i=0;i<n;i++){
        s2= s2 + (1LL*a[i]);
    }
    lli s1 = ((n*1LL)*1LL*(n+1))/2;
    lli p = s2 - s1;
    lli sq= 0;
    for(int i=0;i<n;i++){
        sq += (a[i]*1LL* a[i]) - ((i+1)*1LL*(i+1));
    }
    lli y_p_x = sq/(p);
    vector<int> ans;
    ans.push_back((y_p_x*1LL + p)/2);
    ans.push_back((y_p_x*1LL - p)/2);
    return ans;
}

// Best approach with leasy memory and time. 
vector<int> repeatedNumber(const vector<int> &a) {

    int n= a.size();
    lli p = 0;
    lli sq= 0;
    for(int i=0;i<n;i++){
        p += (a[i]*1LL) - (i+1)*1LL;
        sq += (a[i]*1LL* a[i]) - ((i+1)*1LL*(i+1));
    }
    lli y_p_x = sq/(p);
    vector<int> ans;
    ans.push_back((y_p_x*1LL + p)/2);
    ans.push_back((y_p_x*1LL - p)/2);
    return ans;
}

int main(){
    
    return 0;
}