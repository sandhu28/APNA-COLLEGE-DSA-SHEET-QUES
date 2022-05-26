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

// a - 97 and z - 122
// A - 65 and Z - 90
// 0 - 49 and 9 - 57
// Not a neat and clean solution
bool isPalindrome(string s) {
    string new_s= "";
    int n= s.size();
    for(int i=0;i<n;i++){
        // z(s[i]);
        int ch = s[i];
        if((ch>=65) && ch<=90){
            char chr= (char)(ch+32);
            new_s+= chr;
        }
        else if((ch>=97 && ch<=122) || (ch>= 48 && ch<= 57)){
            new_s += s[i];
        }
        else{
            continue;
        }
    }
    c(new_s);
    int st=0;int en= new_s.size()-1;
    bool t= true;
    while(st<=en){
        if(new_s[st]!= new_s[en]){
            t= false;
            break;
        }
        st++;en--;
    }
    return t;
}

// Neat and clean and better solution
bool isPalindrome(string s) {
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        while(isalnum(s[i])==false && i<j){i++;}
        while(isalnum(s[j])==false && i<j){j--;}
        if(toupper(s[i])!= toupper(s[j])){
            return false;
        }
    }
    return true;
}
int main(){
    
    string s;
    getline(cin,s);
    // c(s);
    // c(isPalindrome(s));
    // int ch= '0';
    // c(ch);
    char ch= 'a';
    c(toupper(ch));
    return 0;
}