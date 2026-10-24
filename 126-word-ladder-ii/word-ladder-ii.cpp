
class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void f(string word, vector<string>& sq) {
        if (word == b) {
            reverse(sq.begin(), sq.end());
            ans.push_back(sq);
            reverse(sq.begin(), sq.end());
            return;
        }

        int dis = mp[word];

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (mp.find(word) != mp.end() &&
                    mp[word] + 1 == dis) {
                    sq.push_back(word);
                    f(word, sq);
                    sq.pop_back();
                }
            }

            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(
        string bword,
        string eword,
        vector<string>& word
    ) {
        mp.clear();
        ans.clear();
        b = bword;

        unordered_set<string> st(word.begin(), word.end());

        if (!st.count(eword))
            return ans;

        queue<string> q;
        q.push(bword);
        mp[bword] = 1;
        st.erase(bword);

        while (!q.empty()) {
            string str = q.front();
            q.pop();

            int dis = mp[str];

            if (str == eword)
                break;

            for (int i = 0; i < str.size(); i++) {
                char original = str[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;

                    if (st.count(str)) {
                        q.push(str);
                        st.erase(str);
                        mp[str] = dis + 1;
                    }
                }

                str[i] = original;
            }
        }

        if (mp.count(eword)) {
            vector<string> sq;
            sq.push_back(eword);
            f(eword, sq);
        }

        return ans;
    }
};
