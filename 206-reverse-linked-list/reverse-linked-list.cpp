
class Solution {
public:
    ListNode* f(ListNode* head){

        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newh = f(head->next);
        ListNode* front = head->next ;
        front->next = head;
        head->next = NULL;
        return newh;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        
        // ListNode* prev = nullptr,*temp = head, *front = head->next;

        // while(temp != NULL){
        //     front = temp->next;
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }

        // return prev;
        return f(head);
    }
};