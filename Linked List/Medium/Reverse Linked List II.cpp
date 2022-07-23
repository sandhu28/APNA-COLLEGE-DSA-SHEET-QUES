#include<iostream>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vlli vector<lli>
#define vli vector<li>
#define all(x) (x).begin(),(x).end()
#define fo(i,n) for(int i=0;i<n;i++)
#define foe(i,k,n) for (int i = k; i < n; ++i)
#define Repr(i,k,n) for (int i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" " 
#define nl cout<<endl;
#define INF INT_MAX
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5+ 3;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverse(ListNode* st,ListNode* en){
    ListNode* prev=NULL,*curr= st,*nxt= st->next;
    while(prev!=en){
        curr->next= prev;
        prev= curr;
        curr= nxt;
        if(nxt){
            nxt= nxt->next;
        }
    }
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* temp= head;
    int idx=1;
    ListNode* beforeStart= new ListNode(-1);
    beforeStart->next= head;
    ListNode* en= NULL;
    while(idx<=right){
        if(idx+1==left){
            beforeStart= temp;
        }
        if(idx==right){
            en= temp;
        }
        idx++;
        temp= temp->next;
    }
    ListNode* afterEn= en->next;
    ListNode* st= beforeStart->next;
    reverse(st,en);
    beforeStart->next= en;
    st->next= afterEn;
    return head;
}

int main(){
    
    return 0;
}