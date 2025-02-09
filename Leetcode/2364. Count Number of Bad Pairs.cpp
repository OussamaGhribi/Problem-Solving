class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    unordered_map<int, int> freq;
    long long n = nums.size();
    long long totalPairs = (n * (n - 1)) / 2;
    long long goodPairs = 0;
    
    for (int i = 0; i < n; i++) {
        int key = i - nums[i];
        if (freq.count(key)) {
            goodPairs += freq[key];
        }
        freq[key]++;
    }
    
    return totalPairs - goodPairs;
}

};
