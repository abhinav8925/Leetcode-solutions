class Solution {
    vector<vector<int>>memo;

public:
    int helper(vector<int>&ar,int idx,bool takeIt,int prev,int diff){
        
    if((idx>=ar.size()-2 && !takeIt) || idx>=ar.size() || ar.size()<3){
        return 0;
    }
    
    if( memo[idx][takeIt]!=-1){
        return memo[idx][takeIt];
    }
     
    if (takeIt){
        if(ar[idx]-prev == diff){
            return memo[idx][takeIt] = 1+ helper(ar,idx+1,1,ar[idx],diff);
        } else return memo[idx][takeIt] = 0;
    }
        
     int pick = 0;
        
     if(ar[idx+1]-ar[idx] == ar[idx+2]-ar[idx+1]){ // diff between to consictuve is  equal
         pick = 1 + helper(ar,idx+3,1,ar[idx+2],ar[idx+1]-ar[idx]);
     }
	 
    int leave =  helper(ar,idx+1,0,0,0);
    
	memo[idx][takeIt] = pick+leave; // memoization    
    return pick+leave;
}
    
int numberOfArithmeticSlices(vector<int>& nums) {
     memo = vector<vector<int>>(nums.size(),vector<int>(2,-1));
    return helper(nums,0,0,0,0);
}

};