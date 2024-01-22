class Solution {
public:
    struct comp {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
            if (a.first.size() == b.first.size()) {
                if (a.first == b.first)
                    return a.second < b.second;

                return a.first < b.first;
            }
            return a.first.size() < b.first.size();
        }
    };

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

        vector<int> ans;
        for (auto it : queries) {

            int k = it[0];
            int len = it[1];

            priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;

            for (int i = 0; i < nums.size(); i++) {
                string num = nums[i];
                string trim = num.substr(num.size() - len);
                pq.push({ trim, i });
            }
            while (pq.size() > k)
                pq.pop();

            string small = pq.top().first;
            int ind = pq.top().second;

            while (pq.size() > 0 && pq.top().first == small && pq.top().second < ind) {
                ind = pq.top().second;
                pq.pop();
            }
            ans.push_back(ind);
        }
        return ans;
    }
};