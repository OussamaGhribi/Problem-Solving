class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;
        res.reserve(spells.size());

        for (int spell : spells) {
            long long minPotion = success / spell;
            if (success % spell != 0) minPotion++;

            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            res.push_back(m - idx);
        }

        return res;
    }
};
