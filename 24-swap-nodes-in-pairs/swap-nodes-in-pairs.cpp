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

// Problem Link -> https://leetcode.com/problems/swap-nodes-in-pairs/

/*
// using recursion
 if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; 
        temp = head->next; 
        
        head->next = swapPairs(head->next->next); 
        temp->next = head; // 
        
        return temp; 


*/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next)
            return head;
        
        ListNode *dum=new ListNode(),*prev=dum,*cur=head;

        while(cur && cur->next){
            prev->next = cur->next;
            cur->next = prev->next->next;
            prev->next->next=cur;

            prev = cur;
            cur = cur->next;
        }

        return dum->next;
        
    }
};