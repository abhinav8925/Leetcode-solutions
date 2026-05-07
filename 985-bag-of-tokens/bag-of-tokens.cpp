class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int l=0,r=n-1;
        int mx=0,score=mx;

        while(l<=r){
            if(power>=tokens[l]){
                score++;
                mx = max(score, mx);
                power-=tokens[l];
                l++;
            }else if(power<tokens[l]){
                if(score>=1){
                    score--;
                    power+=tokens[r];
                    r--;
                }else{
                    return mx;
                }
            }
        }
        return mx;
    }
};