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

// Using inbuilt sort takes 100log(100) to sort 
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    int n= strs.size();
    map<string,vector<string>> m;
    for(auto& e: strs){
        string k = e;
        sort(k.begin(),k.end());
        m[k].push_back(e);
    }
    for(auto &vec: m){
        ans.push_back(vec.second);
    }
    return ans;
}

// Using counting sort here since 'a'to 'z' only
string count_sort(string &s){
    string ans="";
    int n= s.size();
    int arr[26]={};
    for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        ans+= string(arr[i],i+'a');
        // ans+= string(arr[i],char(97+i));
    }
    return ans;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    int n= strs.size();
    map<string,vector<string>> m;
    for(auto& e: strs){
        string k = count_sort(e);
        m[k].push_back(e);
    }
    for(auto &vec: m){
        ans.push_back(vec.second);
    }
    return ans;
}

// Using int as hash key
int give_hash_key(string &s){
    int ans=0;
    int n= s.size();
    for(int i=0;i<n;i++){
        ans+= s[i];
    }
    return ans;
}

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     vector<vector<string>> ans;
//     int n= strs.size();
//     map<int,vector<string>> m;
//     for(auto& e: strs){
//         int k = give_hash_key(e);
//         m[k].push_back(e);
//     }
//     for(auto &vec: m){
//         ans.push_back(vec.second);
//     }
//     return ans;
// }

int main(){
    string s1= "duh";
    string s2= "ill";
    int k= give_hash_key(s1);
    int p= give_hash_key(s2);
    c(k);
    c(p);
    return 0;
}