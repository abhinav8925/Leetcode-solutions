// Problem Link -> https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
            
            unordered_map<int,int> m;
            Node *cur=head,*use=NULL;
            while(cur){
                // int k=cur->data;
                if(m.find(cur->data)!=m.end()){
                    use->next=cur->next;
                    
                }
                else{
                    m[cur->data]=1;
                    use=cur;
                }
                
                cur=cur->next;
            }
            
            return head;
    }
};
