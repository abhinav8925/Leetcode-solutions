
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* prev = nullptr,*temp = head, *front = head->next;

        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};