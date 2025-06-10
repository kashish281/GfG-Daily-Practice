// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(vector<vector<int>> &mat) {
        // code here
        int R = mat.size();
        int C = mat[0].size();
        int maxSum = INT_MIN;

        for (int top = 0; top < R; top++) {
            vector<int> temp(C, 0);

            for (int bottom = top; bottom < R; bottom++) {
                for (int col = 0; col < C; col++) {
                    temp[col] += mat[bottom][col];  // collapsing row elements into temp
                }

                // Apply Kadane's algorithm on temp[]
                int currentSum = temp[0], maxCurrent = temp[0];
                for (int i = 1; i < C; i++) {
                    currentSum = max(temp[i], currentSum + temp[i]);
                    maxCurrent = max(maxCurrent, currentSum);
                }

                maxSum = max(maxSum, maxCurrent);
            }
        }
        return maxSum;
    }
        
    
};
