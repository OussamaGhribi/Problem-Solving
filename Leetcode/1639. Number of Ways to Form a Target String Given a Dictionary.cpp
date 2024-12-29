class Solution {
public:
const int MOD = 1e9 + 7;
int numWays(vector<string>& words, string target) {
    int m = words[0].size(); 
    int n = target.size(); 
    vector<vector<int>> freq(m, vector<int>(26, 0)); 
    
    for (string& word : words) {
        for (int i = 0; i < m; i++) {
            freq[i][word[i] - 'a']++;
        }
    }

    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][n] = 1; 
    
    for (int j = n - 1; j >= 0; j--) {          
        for (int i = m - 1; i >= 0; i--) {      
            dp[i][j] = dp[i + 1][j];            
            if (freq[i][target[j] - 'a'] > 0) { 
                dp[i][j] += freq[i][target[j] - 'a'] * dp[i + 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }

    return dp[0][0];
}

};
