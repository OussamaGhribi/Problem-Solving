class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> rep;
        int target = nums.size()/2;
        for(int i = 0 ; i < nums.size(); i++){
            rep[nums[i]]++;
        }
        for(auto p : rep){
            if(p.second == target) {
                return p.first;
            }
        }
        return -1;
    }
};
