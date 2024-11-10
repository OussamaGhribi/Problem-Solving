class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int prev = -1;
        int j = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==prev){
                j = i;
            }
            ans+=(i-j+1);
            prev = nums[i];
        }
        return ans;
    }
};