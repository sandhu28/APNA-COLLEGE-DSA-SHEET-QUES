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

int countValidWords(string s) {
    int n= s.size();
    string word;
    stringstream ns(s);
    int ans=0;
    while(ns >> word){
        bool f=1;
        int no_of_hype= 0;
        int no_of_punc= 0;
        bool dig=0;
        for(int i=0;i<word.size();i++){
            int m= word.size();
            char ch= word[i];
            if(isupper(ch)){
                f=0;
                break;
            }
            else if(ch== '-'){
                no_of_hype++;
                if(i-1>=0 && islower(word[i-1]) && (i+1<m) && islower(word[i+1])){
                    continue;
                }
                else{
                    f=0;
                    break;
                }
            }
            else if(isdigit(ch)){
                dig=1;
                f=0;break;
            }
            else {
                no_of_punc++;
                if(i!=m-1){
                    f=0;
                    break;
                }
            }
        }
        if(no_of_hype>1 || no_of_punc>1){
            f=0;
        }
        if(f){
            ans++;
        }
    }
    return ans;
}

int main(){
    
    return 0;
}