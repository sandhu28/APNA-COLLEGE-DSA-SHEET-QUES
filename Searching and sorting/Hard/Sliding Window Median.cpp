#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (int i = k; i < n; ++i)
#define Repr(i, k, n) for (int i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

vector<double> medianSlidingWindow(vector<int> &vec, int k)
{
    int n = vec.size();
    vector<double> ans;
    vector<double> v;
    for(int i=0;i<n;i++){
        v.push_back((double)vec[i]);
    }
    if (k == 1)
    {
        for (auto &e : v)
        {
            ans.push_back(1.0*e);
        }
        return ans;
    }
    if (k == 2)
    {
        for (int i = 1; i < n; i++)
        {
            double div = (v[i]*1.0 + 1.0*v[i - 1])/2;
            ans.push_back(div);
        }
        return ans;
    }
    vector<pair<double,int>> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back({v[i], i});
    }
    sort(temp.begin(), temp.end());
    if(k&1){
        ans.push_back(temp[((k - 1) / 2)].first);
    }
    else{
        ans.push_back((temp[(k-1)/2].first + temp[k/2].first)/2);
    }
    set<pair<double,int>> ls;
    set<pair<double,int>> rs;
    for (int i = 0; i < (k / 2) + (k % 2); i++)
    {
        ls.insert(temp[i]);
    }
    for (int i = (k / 2) + (k % 2); i < k; i++)
    {
        rs.insert(temp[i]);
    }
    for (int j = k; j < n; j++)
    {
        if (ls.find({v[j - k], j - k}) != ls.end())
        {
            ls.erase({v[j - k], j - k});
        }
        else
        {
            rs.erase({v[j - k], j - k});
        }
        if (ls.rbegin()->first < v[j])
        {
            rs.insert({v[j], j});
        }
        else
        {
            ls.insert({v[j], j});
        }
        while (ls.size() < (k / 2) + (k % 2))
        {
            auto pr = *rs.begin();
            ls.insert(pr);
            rs.erase(pr);
        }
        while (rs.size() < (k / 2))
        {
            auto pr = *ls.rbegin();
            rs.insert(pr);
            ls.erase(pr);
        }
        double n1= ls.rbegin()->first;
        double n2= rs.begin()->first;
        if(k&1){ans.push_back(n1);}
        else{ans.push_back((n1+n2)/2);}
    }
    return ans;
}
int main()
{

    return 0;
}