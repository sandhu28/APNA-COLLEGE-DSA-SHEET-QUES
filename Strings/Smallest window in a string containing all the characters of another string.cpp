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

string smallestWindow (string s, string p)
{
    int n= s.size();
    int m = p.size();
    if(m>n){return "";}
    int st=0,en=0;
    int mn= INT_MAX;
    int i=INT_MAX,j=0;
    unordered_map<char,int> um;
    for(int i=0;i<m;i++){
        um[p[i]]++;
    }
    int ct= um.size();
    while(st<=en && en<n){
        if(ct==0){
            while(ct==0 && st<=en){
                if(en-st+1< mn){mn= en-st+1;i=st;j=en;}
                else{
                    if(en-st+1==mn){
                    if(i>st){
                        i=st;j=en;
                    }
                }
                }
                if(um.find(s[st])!=um.end()){
                    um[s[st]]++;
                    if(um[s[st]]==1){
                        ct++;
                        en++;
                    }
                }
                st++;
                
            }
        }
        else{
            if(um.find(s[en])!=um.end()){
                um[s[en]]--;
                if(um[s[en]]==0){
                    ct--;
                }
            }
            if(ct>0){
                en++;
            }
        }
    }
    if(mn==INT_MAX){
        return "";
    }
    return s.substr(i,j-i+1);
}

// Geeks for geeks solution nice sol look at it once.
string Minimum_Window(string s, string t)
{
 
    int m[256] = { 0 };
 
    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0; // starting index of ans
    int count = 0;
   
    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }
 
    // References of Window
    int i = 0;
    int j = 0;
 
    // Traversing the window
    while (j < s.length()) {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
 
        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Sorting ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I
 
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
 
                i++;
            }
        }
        j++;
    }
 
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}
int main(){
    string s;cin>>s;
    string p; cin>>p;
    c(smallestWindow(s,p));
    // c(Minimum_Window(s,p));
    
    return 0;
}