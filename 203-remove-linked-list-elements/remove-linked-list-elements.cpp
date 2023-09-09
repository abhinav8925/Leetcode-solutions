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

 // Problem Link -> https://leetcode.com/problems/remove-linked-list-elements/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {


        if(head==NULL)
            return NULL;
        
        while(head!=nullptr && head->val==val){
            head = head->next;
        }

        ListNode *prev=NULL,*cur=head;

        while(cur!=NULL){
            if(cur->val == val){
                prev->next = cur->next;
            }
            else
                prev=cur;
            
            cur=cur->next;
        }

        return head;

        
    }
};