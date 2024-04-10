class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(begin(deck),end(deck));

        vector<int> ans(n,0);

        int ind=0;
        bool skip = false;
        
        int i=0,j=0;

        while(i<n){
            
            if(ans[j]==0){
                if(skip == false){
                    ans[j] = deck[i++];
                }
                skip= !skip;

            }
            j = (j+1)%n;
        }
        return ans;
    }
};