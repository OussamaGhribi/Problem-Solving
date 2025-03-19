class Solution {
public:
    static int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int i0 = -1, op = 0;

        while (i0 < n - 2) {
            i0 = find(nums.begin() + i0 + 1, nums.end(), 0) - nums.begin();
            if (i0 >= n - 2)
                break; 
            nums[i0 + 1] = !nums[i0 + 1];
            nums[i0 + 2] = !nums[i0 + 2];
            op++;
        }

        return (i0 >= n) ? op : -1;
    }
};
