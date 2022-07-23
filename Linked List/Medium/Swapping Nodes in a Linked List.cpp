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


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int ct=0;
        ListNode* temp= head;
        while(temp!=NULL){
            temp=temp->next;
            ct++;
        }
        int n=ct;
        ct=0;
        temp= head;
        ListNode* st=NULL;
        ListNode* en= NULL;
        while(temp!=NULL){
            if(ct==k-1){
                st= temp;
            }
            else if(ct==n-k ){
                en= temp;
            }
            temp=temp->next;
            ct++;
        }
        swap(st->val,en->val);
        return head;
    }
   
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1=NULL;
        ListNode* n2= NULL;
        for(ListNode* p= head;p!=NULL;p= p->next){
            if(n2){n2= n2->next;}
            if(--k==0){
                n1= p;
                n2= head;
            }
        }
        swap(n1->val,n2->val);
    }
};

int main(){
    
    return 0;
}