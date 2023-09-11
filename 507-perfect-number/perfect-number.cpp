// Problem Link -> https://leetcode.com/problems/perfect-number/description/

class Solution
{
    public:
        bool checkPerfectNumber(int N)
        {

            long sum = 1;
            for (int i = 2; i < sqrt(N); i++)
            {
                if (N % i == 0)
                {
                    if (i != N) sum += i + (N / i);
                }
            }
            if (sum == N && N != 1)
            {
                return 1;
            }
            return 0;
        }
};