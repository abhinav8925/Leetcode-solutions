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
class Solution {
public:

    ListNode *rev(ListNode *head){
        ListNode *prev=nullptr,*fwd=head,*cur=head;
        while(cur){
            fwd = cur->next;
            cur->next = prev;
            prev=cur;
            cur = fwd;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode *fast=head,*slow=head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = rev(slow);
        ListNode *curr = head,*temp1,*temp2;

        while(slow->next){
            temp1 = curr->next;
            curr->next = slow;
            temp2 = slow->next;
            slow->next = temp1;
            curr = temp1;
            slow = temp2;
        }
        
    }
};