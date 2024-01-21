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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;
        ListNode* pre = NULL;
        while(temp != NULL){

            int k = 1;
            ListNode* curr = temp; 
            while((temp != NULL) && (temp->val == curr->val)){
                temp = temp->next;
                k++;
            }
            k--;

            if(k == 1){

    
  
                if(pre == NULL){
                    head = curr;
                    pre = curr;
                }

                else{
                    pre->next = curr;
                    pre = curr;
                }
            }

            if(temp == NULL && pre != NULL){
                pre->next = temp;
            }
        } 

        
        if(pre == NULL){
            head = NULL;
        }
        return head;
    }
};