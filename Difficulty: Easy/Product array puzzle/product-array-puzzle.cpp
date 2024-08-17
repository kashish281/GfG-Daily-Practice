//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
         int n = nums.size();
        
        vector<long long int> ans(n, 1);
        
        // Calculate the prefix product
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        long long int val = 1;
        
        // Calculate the suffix product
        for (int i = n - 2; i >= 0; --i) {
            ans[i] *= val * nums[i + 1];
            val *= nums[i + 1];
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends