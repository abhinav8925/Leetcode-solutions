
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                break;
            }
        }
        if(!fast || !fast->next)
            return nullptr;

        ListNode* start = head;
        while(start != slow){
            start = start->next;
            slow = slow->next;
        }

        return start;
    }
};