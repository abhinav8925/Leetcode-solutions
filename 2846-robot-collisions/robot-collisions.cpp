class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> answer;
        priority_queue<pair<int, pair<int,int> >> r;
        set<pair<int,  pair<int,int> >> l;
        
        
        for(int i = 0; i < directions.size(); i++){
            if(directions[i] == 'L'){
                l.insert({positions[i], {healths[i], i}});
            }else{
                r.push({positions[i], {healths[i], i}});
            }
        }
        
        
        while(r.size()){
            int pos = r.top().first, h = r.top().second.first, idx = r.top().second.second;
            r.pop();
            
            auto ptr = l.lower_bound({pos, {0, 0}});
            
            if(ptr == l.end()){
                answer.push_back({idx, h});
                continue;
            }
            
            int x = ptr->second.first;
            int id = ptr->second.second;
            
            if(h > x){
                l.erase(ptr);
                r.push({pos, {h -1, idx}});
                continue;
            }else if( x > h){
                l.erase(ptr);
                l.insert({pos, {x- 1, id} });
                continue;
            }else{
                l.erase(ptr);
            }
        }
        
        
        
        for(auto i : l){
            answer.push_back({i.second.second, i.second.first});
        }
        sort(answer.begin(), answer.end());
        
        
        vector<int> temp;
        for(auto i : answer){
            temp.push_back(i.second);
        }
        return temp;
    }
};