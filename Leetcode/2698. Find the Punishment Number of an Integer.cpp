class Solution {
public:
    bool canPartition(string sqStr, int target, int index = 0, int currentSum = 0) {
        if (index == sqStr.length()) {
            return currentSum == target; 
        }
        
        int num = 0;
        for (int i = index; i < sqStr.length(); i++) {
            num = num * 10 + (sqStr[i] - '0'); 
            if (canPartition(sqStr, target, i + 1, currentSum + num)) {
                return true;  
            }
        }
        
        return false;  
    }

    int punishmentNumber(int n) {
        int total = 0;
        
        for (int i = 1; i <= n; i++) {
            string sqStr = to_string(i * i); 
            
            if (canPartition(sqStr, i)) {  
                total += i * i;  
            }
        }
        
        return total;
    }
};
