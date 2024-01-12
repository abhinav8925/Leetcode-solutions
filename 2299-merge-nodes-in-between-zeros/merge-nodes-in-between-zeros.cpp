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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL || head->val==0 && head->next==NULL)  
            return nullptr;
        
        ListNode *dummy=new ListNode(-1);
        ListNode* ans=dummy;
        while(head!=nullptr){
                int sum=0;
                while(head!=nullptr && head->val!=0){
                    sum+=head->val;
                    head=head->next;
                }
                ans->next = new ListNode(sum);
                ans=ans->next;

                if(head!=NULL || head->val==0)
                    head=head->next;
        }

        return dummy->next->next;
    }
};