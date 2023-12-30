class Solution {
public:

    bool makeEqual(vector<string>& words) {

        
        vector<int> characterCount(26, 0);

        for (const string& inputWord : words) {
            
            for (char inputChar : inputWord) {
                
                characterCount[inputChar - 'a']++;
            }
        }

    
        for (int count : characterCount) {
            if (count % words.size() != 0) {
               
                return false;
            }
        }

        
        return true;
    }
};