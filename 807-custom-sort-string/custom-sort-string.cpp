class Solution {
public:
    string customSortString(string order, string s) {
        
        string outOfOrder = "";
        string inOrder = "";
        
        int Sum[26] = {0};
        
        for(auto i : order)
        {
            Sum[i - 'a']++;
        }
        
        for(auto i : s)
        {
            if(Sum[i - 'a'] == 0)
            {
                outOfOrder = outOfOrder + i;
            }
            
            else
            {
                Sum[i-'a']++;
            }
        }
        
        
        for(auto i : order)
        {
            while(Sum[i - 'a'] > 1)
            {
                inOrder = inOrder + i;
                Sum[i - 'a']--;
            }
        }
        
        return inOrder + outOfOrder;
    }
};