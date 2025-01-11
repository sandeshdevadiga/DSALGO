class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        if (n < 2) return 0; // Ensure the string can be split into two non-empty parts
        
        int leftSum = 0; // Number of zeros in the left part
        int rightSum = 0; // Number of ones in the right part
        
        // Initialize the right sum with the total count of '1's in the string
        for (char c : s) {
          rightSum+=c-'0';         
        }
        
        int maxSum = 0;
        
        // Iterate through the string, updating leftSum and rightSum
        for (int i = 0; i < n - 1; ++i) { // n-1 ensures both parts are non-empty
          rightSum-=s[i]=='1';
          leftSum+=s[i]=='0';
            
            maxSum = max(maxSum, leftSum + rightSum);
        }
        
        return maxSum;
    }
};