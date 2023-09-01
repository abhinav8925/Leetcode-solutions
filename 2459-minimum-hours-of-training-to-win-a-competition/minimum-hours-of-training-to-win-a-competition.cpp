// Problem Link -> https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int training=0,n=energy.size();
        for(int i=0;i<n;i++)
        {
            if(energy[i]>=initialEnergy)
            {
                int diff=energy[i]-initialEnergy;
                training+=diff+1;
                initialEnergy+=diff+1;
            }
            if(experience[i]>=initialExperience)
            {
                int diff=experience[i]-initialExperience;
                training+=diff+1;
                initialExperience+=diff+1;
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }
        return training;
    }
};