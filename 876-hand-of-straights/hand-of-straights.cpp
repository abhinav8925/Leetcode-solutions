class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        
        while(!mp.empty()){
            int cur = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp.find(cur+i)==mp.end() || mp[cur+i]==0)
                    return 0;
                
                mp[cur+i]--;
                if(mp[cur+i]==0)
                    mp.erase(cur+i);
            }
        }
        return true;
    }
};