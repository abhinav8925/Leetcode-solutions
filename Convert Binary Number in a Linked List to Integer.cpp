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

 // Problem Link -> https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/


// another method -> run twice and in first find the length and in second ans+=pow(2,length-1),length--;
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        /*int num=0;
        string s;

        while(head!=NULL){
            if(head->val==1)
                s.push_back('1');
            else
                s.push_back('0');

            head=head->next;
        }

        int p = 0, k = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') { 
                k = 1 << p; 
                
            } else {
                k = 0;
            }
            p++;
            num += k;
        }
        return num;
        */
        // another method -> using the concept of one pass and in forward from left
        //
        // 1001 -> ans*2+s[i];

        int ans=0;
        while(head!=NULL){
            ans=ans*2+head->val;
            head=head->next;
        }

        return ans;
    }
};
