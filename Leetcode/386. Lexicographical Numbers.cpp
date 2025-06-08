class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Create a vector of strings
        vector<string> numbers;
        
        // Convert all integers from 1 to n into strings
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(to_string(i));
        }
        
        // Sort the vector lexicographically
        sort(numbers.begin(), numbers.end());
        
        // Convert back to integers
        vector<int> result;
        for (int i = 0; i < n; ++i) {  // Loop should iterate over 'numbers'
            result.push_back(stoi(numbers[i]));  // Use 'numbers' here, not 'result'
        }
        
        return result;
    }
};
