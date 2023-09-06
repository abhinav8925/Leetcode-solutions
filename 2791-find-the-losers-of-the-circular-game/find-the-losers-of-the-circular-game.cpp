// Problem Link -> https://leetcode.com/problems/find-the-losers-of-the-circular-game/

class Solution {
public:
    

    vector<int> circularGameLosers(int n, int k) {
        
    vector<int> ans(n, 0);
    
    int i = 1,s=0;
    ans[s]++;
    while (ans[s]!=2) {
        s = (s +(i* k )) % n; 
        ans[s]++;  
       i++; 
    }

    vector<int> v;
    for (int i = 0; i <n; i++) {
        if (ans[i] == 0)
            v.push_back(i+1);  
    }

    return v;
}

};