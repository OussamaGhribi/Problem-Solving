class Solution {
public:
    const int MOD = 1e9 + 7;

    int power(int base, int exp) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * b) % MOD;
            b = (b * b) % MOD;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + power(2, right - left)) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};
