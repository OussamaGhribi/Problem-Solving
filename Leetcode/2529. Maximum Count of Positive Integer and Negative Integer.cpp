class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int sp = 0, sn =0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                sn += 1;
            }else if(nums[i]>0){
                sp += 1;
            }
        }
        return max(sp,sn);
    }
};
