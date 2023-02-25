class Solution {
public:
    int maximum69Number (int num) {
        int k=num;
        vector<int> v;

        while(k!=0)
        {
            int j=k%10;
            v.push_back(j);
            k/=10;
        }
        for(int i=v.size()-1;i>=0;i--)
        {
                if(v[i]==6)
                  {
                        v[i]=9;
                        break;
                  }  
                    
        }
        int ans=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            ans=ans*10+v[i];
        }
        
        return ans;
    }
};
