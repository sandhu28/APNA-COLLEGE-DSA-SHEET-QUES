#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(), (x).end()
#define fo(i, n) for (int i = 0; i < n; i++)
#define foe(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 3;

class FoodRatings
{
public:
    bool comp=[](pair<int,string> &a, pair<int,string> &b)
    {
        if(a.first==b.first){
            return a.second.size()> b.second.size();
        }
        return a.first<b.first;
    };
    map<string, pair<int,string>> m;
    map <string, set<pair<int,string>>> mp;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n= foods.size();
        fo(i,n){
            m[foods[i]]= {ratings[i],cuisines[i]};
            mp[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    void changeRating(string food, int newRating)
    {
        int oldRat = m[food].first;
        auto c = m[food].second;
        m[food]= {newRating,c};
        auto it= mp[c].lower_bound({oldRat,food});
        // it->first= newRating;
        mp[c].erase(it);
        mp[c].insert({newRating,food});
    }

    string highestRated(string cuisine)
    {
        auto st= mp[cuisine];
        auto val = *(--st.end());
        // auto k= st.lower_bound()
        auto it= st.lower_bound({val.first,"a"});
        return val.second;
    }
};

int main()
{

    return 0;
}