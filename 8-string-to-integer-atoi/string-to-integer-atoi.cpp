class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        long long sign = 1;
        int i = 0;
        int n = s.size();
        while(i<n && s[i]== ' '){
            i++;
        }

        if(i<n  && (s[i] == '-') || (s[i] == '+')){
            if(s[i] == '-')
                sign=-1;
            i++;
        }
        
        while(i < n && s[i] >= '0' && s[i] <= '9') {
                int dig = s[i]-'0';
                long long limit;
                if(sign == 1){
                    limit = INT_MAX;
                }else
                    limit = -(long long)INT_MIN;

                if(ans > (limit-dig) / 10){
                    if(sign == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }

                ans=ans*10 + dig;
            
            i++;
        }
        return (int)ans*sign;
    }
};