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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ans = new ListNode(head->val);
        ListNode *cur = head->next;
        
        while(cur!=NULL){
            
            ListNode *prev = nullptr;
            ListNode *nxt = cur->next;
            ListNode *temp = ans;
            
            while(temp!=NULL && temp->val < cur->val){
                prev = temp;
                temp = temp->next;
            }
            
            if(prev == nullptr){
                cur->next = temp;
                ans = cur;
            }
            else if(prev->next == nullptr){
                prev->next = cur;
                cur->next=NULL;
            }
            else{
                prev->next = cur;
                cur->next = temp;
            }
            
            cur = nxt;
            
        }
        
        return ans;
    }
};