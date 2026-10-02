
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int del = cnt-n;
        if(del == 0)
            return head->next;
        
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        int tt=0;
        while(tt != del){
            tt++;
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        cur->next = nullptr;
        return head;

    }
};