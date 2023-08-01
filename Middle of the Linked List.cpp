 // Problem Link ->  https://leetcode.com/problems/middle-of-the-linked-list/


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *first=head,*second=head;
        while(first && first->next){
            
            second=second->next;
            first=first->next->next;

        }
        return second;
    }
};
