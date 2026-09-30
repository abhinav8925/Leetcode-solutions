
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* first = head, *second = head;
        while(second && second->next){
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};