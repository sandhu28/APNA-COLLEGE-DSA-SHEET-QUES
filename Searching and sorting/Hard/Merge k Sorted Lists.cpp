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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    ListNode *mergeKLists(vector<ListNode*> &lists)
    {
        bool comp = [](ListNode *&a, ListNode *&b)
        {
            return a->val < b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
            {
                pq.push(lists[i]);
            }
        }

        ListNode *prev = NULL;
        ListNode *root= NULL; 
        while (!pq.empty())
        {
            auto tp = pq.top();
            pq.pop();
            if(prev==NULL){
                prev= tp;
                root=prev;
                if(tp->next!=NULL){
                    pq.push(tp->next);
                }
                continue;
            }
            prev->next= tp;
            prev= prev->next;
            if(tp->next!=NULL){
                pq.push(tp->next);
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}