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

// Problem Link -> https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
        return NULL;
    
    
        ListNode *f=head;
        ListNode *s=head;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        
        ListNode *del=head;
        while(del->next!=s)
            del=del->next;
        
        del->next=del->next->next;

        return head;
    }
};
