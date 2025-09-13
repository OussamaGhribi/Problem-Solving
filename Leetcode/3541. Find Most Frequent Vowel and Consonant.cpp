class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> freqV , freqC;
        string vowels = "aeiouAEIOU";
        int maxV = 0 , maxC = 0;

        for(char c : s){
            if(vowels.find(c) != -1){
                freqV[c]++;
            }else{
                freqC[c]++;
            }
        }

        for(auto &p : freqV){
            maxV = max(maxV, p.second);
        }

        for(auto &p : freqC){
            maxC = max(maxC, p.second);
        }

        return maxV + maxC;

    }
};
