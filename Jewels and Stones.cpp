// Problem Link -> https://leetcode.com/problems/jewels-and-stones/

// Brute Force 

// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) {
//         int cnt=0;
       
//         for(char stone : stones){
//             if(jewels.find(stone)!=string::npos)
//                 cnt++;
//         }
//         return cnt;
//     }
// };

// Optimal 

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt=0;
        set<char> js(jewels.begin(), jewels.end());
        int count = 0;

        for (char stone : stones) {
            if (js.find(stone) != js.end()) {
                count++;
            }
        }

        return count;
       
    }
};
