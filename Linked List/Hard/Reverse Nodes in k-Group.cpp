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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==1){
        return head;
    }
    ListNode* st=head,*en= head;
    int ct=k-1;
    while(ct--){
        en= en->next;
        if(en==NULL){
            return head;
        }
    }
    ListNode* newHead = reverseKGroup(en->next,k);
    ListNode* prev=NULL,*curr= head,*nxt= head->next;
    while(curr){
        curr->next= prev;
        prev= curr;
        curr= nxt;
        if(nxt){
            nxt= nxt->next;
        }
    }
    st->next = newHead;
    return en;
}

void reverseList(ListNode* st,ListNode* en){
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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==1){
        return head;
    }
    ListNode* dummy= new ListNode(-1);
    ListNode *en= head;
    dummy->next= head;
    ListNode* BeforeStart= dummy;
    int ct=0;
    while(en!=NULL){
        if(ct%k==0){
            ListNode* st=BeforeStart->next;
            ListNode* temp= en->next;
            reverseList(st,en);
            BeforeStart->next= en;
            st->next= temp;
            BeforeStart= st;
            en= temp;
        }
        else{
            en= en->next;
        }
    }
    return dummy->next;
}

int main(){
    
    return 0;
}