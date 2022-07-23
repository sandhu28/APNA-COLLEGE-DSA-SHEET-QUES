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

// class NumberContainers {

// public:
//     // set<pii> m;
//     map<int,set<int>> mp;
//     NumberContainers() {
//         m.insert({0,0});
//         mp[0]=0;
//     }

//     void change(int index, int number) {
//         mp[index]= number;
//     }

//     int find(int number){
//         auto it= m.lower_bound({number,1e9});
//         if(it==m.end()){
//             return -1;
//         }
//         auto pr= *it;
//         if(pr.first== number){
//             return pr.second;
//         }
//         return -1;
//     }
// };

class NumberContainers
{

public:
    // set<pii> m;
    map<int, set<int>> m;
    map<int, int> m2;
    NumberContainers()
    {
        m[0].insert(0);
    }

    void change(int index, int number)
    {
        if (m2.find(index) == m2.end())
        {
            m2[index] = number;
            m[number].insert(index);
        }
        else
        {
            int num = m2[index];
            if (num != number)
            {
                auto it = m[num].lower_bound(index);
                m[num].erase(it);
                if(m[num].empty()){
                    m.erase(num);
                }
                m2[index] = number;
                m[number].insert(index);
            }
        }
    }

    int find(int number)
    {
        if (m.find(number) == m.end())
        {
            return -1;
        }
        return *m[number].begin();
    }
};

int main()
{

    return 0;
}