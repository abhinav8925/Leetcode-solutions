class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> nums;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
            int idx = mp[val];
            int ele = nums[nums.size()-1];

            nums[idx] = ele;
            mp[ele] = idx;

            nums.pop_back();
            mp.erase(val);
            return true;
        
    }
    
    int getRandom() {
        int randomNum = nums[rand() % nums.size()];
        return randomNum;

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */