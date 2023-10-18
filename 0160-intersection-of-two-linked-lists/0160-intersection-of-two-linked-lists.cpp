/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Problem Link -> https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        
        if(h1==NULL && h2==NULL)
            return NULL;
        
        ListNode *d1=h1;
        ListNode *d2=h2;

        while(d1!=d2){
            if(d1!=NULL)
                d1=d1->next;
            else
                d1=h2;
            if(d2!=NULL)
                d2=d2->next;
            else
                d2=h1;
        }
        return d1;

    }
};