class Solution {
public:
    int NbVowel(const string &s) {
        string vowels = "aeiouAEIOU";
        int count = 0;
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                count++;
            }
        }
        return count;
    }

    bool doesAliceWin(string s) {
        int vowelCount = NbVowel(s);
        return vowelCount > 0;
    }
};
