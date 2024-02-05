class Solution {
public:
    vector<vector<int>> sample;
    vector<int> v;
    int area(vector<int> &r){
        return (r[2]-r[0]+1)*(r[3]-r[1]+1);
    }
    Solution(vector<vector<int>>& rects) {
        sample = rects; 
        int tarea=0;
        for(auto r:sample){
            tarea+=area(r);
            v.push_back(tarea);
        }   
    }
    
    
    vector<int> pick() {
        
        int rnd = rand()%v.back();
        int ind = upper_bound(v.begin(), v.end(), rnd) - v.begin();

        auto r = sample[ind];
        int x = rand()%(r[2]-r[0]+1)+r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */