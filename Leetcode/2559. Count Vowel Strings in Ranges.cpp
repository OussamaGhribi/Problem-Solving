class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        string vowels = "aeiou";
        vector<int> prefix(words.size() + 1, 0);

        for (int i = 0; i < words.size(); i++) {
            char first = words[i][0];
            char last = words[i].back();
            prefix[i + 1] = prefix[i] + (vowels.find(first) != -1 && vowels.find(last) != -1);
        }

        vector<int> res;
        for (auto& q : queries) {
            res.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }

        return res;
    }
};
