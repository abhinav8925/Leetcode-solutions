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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int len = 1;

        while (temp->next) {
            len++;
            temp = temp->next;
        }

        k = k % len;

        if (k == 0)
            return head; 

        temp = head;

        for (int i = 0; i < len - k - 1; i++)
            temp = temp->next;

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        ListNode* temp2 = newHead;
        while (temp2->next)
            temp2 = temp2->next;

        temp2->next = head;

        return newHead;
    }
};
