class Solution {
public:
    string nearestPalindromic(string n) {
   if(n.length()==1) return to_string(stoi(n)-1); 
   int digits=n.length();
   vector<long>candidates;
   candidates.push_back(pow(10,digits-1)-1);
   candidates.push_back(pow(10,digits)+1);

   int mid=(digits+1)/2;
   long prefix=stol(n.substr(0,mid));
 
   vector<long>v={prefix,prefix+1,prefix-1};
   for(long i:v)
   {
       string postfix=to_string(i);
       if(digits%2!=0) postfix.pop_back();
       reverse(postfix.begin(),postfix.end());
       string c=to_string(i)+postfix;
       candidates.push_back(stol(c));
   }
   long mindiff=LONG_MAX;long result;long num=stol(n);
   for(int i=0;i<5;i++)
   {
       if(candidates[i]!=num&&abs(candidates[i]-num)<mindiff){
           mindiff=abs(candidates[i]-num);
           result=candidates[i];
       }
       else if(abs(candidates[i]-num)==mindiff) result=min(result,candidates[i]);
   }
    return to_string(result);
}
};