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

 // Problem Link -> https://leetcode.com/problems/reverse-linked-list/solutions/

class Solution {
public:

    // Iterative  method
    ListNode* itr(ListNode* head){
        ListNode *dummy=NULL;
        // if(head==NULL || head->next==NULL)
        //     return dummy;
        

        while(head!=NULL){
            ListNode *cur=head->next;
            head->next=dummy;
            dummy=head;
            head=cur;
        }

        return dummy;
    
    }

    // Recursive method
    ListNode* rcr(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *newer=rcr(head->next);
        head->next->next=head;
        head->next=NULL;

        return newer;
    }
    ListNode* reverseList(ListNode* head) {
        
        return rcr(head);
    }   
};
