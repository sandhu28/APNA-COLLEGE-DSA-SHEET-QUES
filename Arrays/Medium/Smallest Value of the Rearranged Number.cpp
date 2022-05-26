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

long long smallestNumber(long long num) {
        bool posi= 0;
        if(num>0){posi= 1;}
        else{posi= 0;}
        string s= to_string(num);
        if(!posi){s.erase(0,1);}
        vector<char> vec;
        for(int i=0;i<s.size();i++){
            vec.push_back(s[i]);
        }
        if(posi){
            sort(vec.begin(),vec.end(),[](char &a,char&b){return a<=b;});
            if(vec[0]=='0'){
                for(int j=1;j<vec.size();j++){
                    if(vec[j]!='0'){
                        swap(vec[j],vec[0]);
                        break;
                    }
                }
            }
        }
        else{
            sort(vec.begin(),vec.end(),[](char &a,char&b){return a>=b;});
        }
        string ans= "";
        for(int i=0;i<vec.size();i++){
            ans+= vec[i];
        }
        if(!posi){ans+='-';}
        return stoll(ans);
}

int main(){
    

    return 0;
}