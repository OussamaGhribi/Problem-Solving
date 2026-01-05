class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negCount = 0;
        int minAbs = INT_MAX;
        long long total = 0;

        for (auto& row : matrix) {
            for (int x : row) {
                if (x < 0)
                    negCount++;
                total += abs(x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negCount % 2 == 0)
            return total;
        else
            return total - 2 * minAbs;
    }
};
