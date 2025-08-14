class Solution {
public:
    string largestGoodInteger(string num) {
        map<string, int, greater<string>> mp; 

        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                mp[string(1, num[i])] = 3;
            }
        }

        for (auto &p : mp) {
            return string(3, p.first[0]);
        }

        return "";
    }
};
