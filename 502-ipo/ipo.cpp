class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        

        vector<pair<int,int>> pro(n);

        for(int i=0;i<n;i++){
            pro[i] = {capital[i],profits[i]};
        }   

        sort(pro.begin(),pro.end());
        priority_queue<int> mx;
        int i=0;
        while(k>0){
            while(i<n && pro[i].first<=w){
                   mx.push(pro[i].second);
                   i++;
            }
            
            if(mx.empty())
                break;
            w+=mx.top();
            mx.pop();
            --k;
        }

        return w;
    }
};