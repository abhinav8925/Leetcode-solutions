// Problem Link -> https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
        }

        ans.push_back(arr[dq.front()]);

        for(int i=k;i<arr.size();i++){
            if(i-dq.front()>=k)
                dq.pop_front();
            
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }

        return ans;
    }
};