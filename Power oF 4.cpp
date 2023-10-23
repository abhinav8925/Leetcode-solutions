class Solution {
public:
    bool isPowerOfFour(int n) {

            int cnt1=0;
            int cnt2=0;
			while(n>0)
			{
				if(n&1)	cnt1++;
                if(!(n&1)) cnt2++;
				n=n>>1;
			}
			if(cnt1==1 && cnt2%2==0)	return true;
			else	return false;
    }
};
