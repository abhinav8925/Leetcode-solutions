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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *small=new ListNode(-1000);
        ListNode *smallptr=small;
        ListNode *large=new ListNode(-2000);
        ListNode *largeptr= large;

        while(head){
            if(head->val<x){
                smallptr->next=head;
                smallptr=head;
            }
            else{
                largeptr->next=head;
                largeptr=head;
            }
            head=head->next;
        }

        largeptr->next=NULL;
        smallptr->next=large->next;

        return small->next;
    }
};