class Solution {
public:
    int maxScore(string s) {
    int max_score = 0;
    int n = s.size();

    for (int i = 1; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);

        int left_zeros = count(left.begin(), left.end(), '0');
        int right_ones = count(right.begin(), right.end(), '1');

        int score = left_zeros + right_ones;

        max_score = max(max_score, score);
    }

    return max_score;
}
};
