/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // Problem Link -> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/


// Brute Force -> count length and then find both positions and swap them


// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {

//         int n=0;
//         ListNode *c=head;
//         while(!c){
//             n++;
//             c=c->next;
//         }

//         int l = n-k+1;

//         ListNode *s=NULL,*e=NULL;
//         c=head;
//         int cnt=0;
//         while(c){
//             cnt++;
//             if(cnt==k)
//                 s=c;
            
//             if(c==l)
//                 e=c;
            
//             if(e!=NULL && s!=NULL)
//                 break;

//             c=c->next;
//         }
//         swap(s->val,e->val);
//         return head;

        
//     }
// };


// Optimal  (one pass approach)

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *l=head,*r=head;

        for(int i=0;i<k-1;i++)
            r=r->next;
        
        ListNode *ch=r;

        while(r->next){
            l=l->next;
            r=r->next;
        }

        swap(ch->val,l->val);
        return head;


    }
};