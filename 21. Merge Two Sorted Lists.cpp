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
 // Problem Link -> https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;


        ListNode *ans=list1;

        if(list1->val>list2->val){
            ans=list2;
            list2=list2->next;
        }
        else{
            list1=list1->next;
        }
        
        ListNode *cur=ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val>list2->val){
                cur->next=list2;
                list2=list2->next;
            }
            else if(list1->val<=list2->val){
                cur->next=list1;
                list1=list1->next;
                
            }
            
            cur=cur->next;
        }
        
        if(!list1)
            cur->next=list2;
        else
            cur->next=list1;

        return ans;
    }
};
