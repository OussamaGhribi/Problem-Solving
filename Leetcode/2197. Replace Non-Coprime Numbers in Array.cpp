class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (int num : nums) {
            long long x = num;
            while (!st.empty() && gcd(st.back(), x) > 1) {
                x = lcm(st.back(), x);
                st.pop_back();
            }
            st.push_back(x);
        }

        vector<int> result;
        for (long long val : st) result.push_back((int)val);
        return result;
    }
};
