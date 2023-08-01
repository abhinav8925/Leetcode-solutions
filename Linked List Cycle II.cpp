/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Problem Link -> https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)
            return NULL;
        
        ListNode *f=head,*s=head;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
            if(f==s)
                break;
        }

        if (!(f && f->next)) return NULL;
        
        // s=head;
        while(head!=s){
            head=head->next;
            s=s->next;
            
        }
        return head;
    }
};
