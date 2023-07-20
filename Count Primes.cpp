// Problem Link -> https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) {
        


    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    int cnt = 0;

    for (int i = 2; i <n; i++) {
        if (v[i]) {
            cnt++;
            for (int j = 2 * i; j < n; j += i) {
                v[j] = 0;
            }
        }
    }

    return cnt;
    }
};
