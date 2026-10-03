
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1=0,cnt2=0;

        ListNode* temp=headA;
        while(temp){
            cnt1++;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            cnt2++;
            temp = temp->next;
        }

        
        if(cnt1 > cnt2){
            while(cnt1 > cnt2){
                headA = headA->next;
                cnt1--;
            }
        }else if(cnt1 < cnt2){
            while(cnt1 < cnt2){
                headB = headB->next;
                cnt2--;
            }
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};