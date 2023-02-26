class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> a;
        a.push_back(celsius+273.15);
        a.push_back(celsius*1.80 + 32.00);
        return a;
    }
};
