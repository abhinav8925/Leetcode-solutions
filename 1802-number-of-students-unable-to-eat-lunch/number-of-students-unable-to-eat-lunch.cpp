class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
            int z=0,o=0;
            for(int i=0;i<size(students);i++){
                if(students[i]==1)
                    o++;
                else
                    z++;
            }

            for(int i:sandwiches){
                if(i==1 && o<=0)
                    break;
                else if(i==0 && z<=0)
                    break;
                if(i==1)
                    o--;
                else 
                    z--;
            }

            return max(o,z);
    }
};