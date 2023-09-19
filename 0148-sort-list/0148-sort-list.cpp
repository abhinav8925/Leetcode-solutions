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

// Problem Link -> https://leetcode.com/problems/sort-list/

class Solution {
public:

    ListNode* merge(ListNode* &first, ListNode* &second){
        
        ListNode* ans = NULL;
        
        if(!first)  
            return second;
        
        if(!second)
            return first;
        
        if(first->val<=second->val){
            ans = first;
            ans->next = merge(first->next,second);
        }
        else{
            ans=second;
            ans->next = merge(first,second->next);
        }
        
        return ans;
    }

    ListNode *findmid(ListNode *head){
        
        ListNode *s=head,*f=head->next;
        
        while(f && f->next){
            s= s->next;
            f=f->next->next;
        }
        
        return s;
    }
    ListNode* sortList(ListNode* head) {

         if(!head || !head->next)
            return head;
        
        ListNode *mid  = findmid(head);
        
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next=NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        
        ListNode *res = merge(left,right);
        
        return res;
        
    }
};