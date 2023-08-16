// Problem Link -> https://leetcode.com/problems/pascals-triangle/

class Solution {
public:

    int ncr(int n, int r){
        int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }

        return res;
    }


    vector<int> generateRow(int row){
        long long ans=1;
        vector<int> v;
        v.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            v.push_back(ans);

        }
        return v;
    }
    vector<vector<int>> generate(int N) {
        
        // type 1 -> given row and col number print the pascals element 
        // answer is -> (row-1)C(col-1)(NcR)
        // short cut for factorial is -> 10C3 = 10*9*8/3*2*1,  10 will multiplied only till 3 places


        // type 2-> print the nth row of the pascals triangle
        // answer is run a loop till the nth times and do the nCr to get each element
    /*
    for(int i=1;i<=n;i++){
        cout << ncr(n-1,i-1);
    }

    or
    int res=1;
    take 0 based col indexing
    for(int i=1;i<n;i++){
        res=res*(n-i);
        ans=ans/(i);
        cout << ans << endl;
    }
    */


    // given n print the whole pascals triangle

    vector<vector<int>> ans2;

    for(int i=1;i<=N;i++){
        ans2.push_back(generateRow(i));
    }

    return ans2;

    }
};
