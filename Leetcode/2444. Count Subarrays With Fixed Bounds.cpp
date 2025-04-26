class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int start = 0, minPos = -1, maxPos = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                start = i + 1;
                minPos = -1;
                maxPos = -1;
            }
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            
            if (minPos != -1 && maxPos != -1) {
                count += std::min(minPos, maxPos) - start + 1;
            }
        }
        
        return count;
    }
};
