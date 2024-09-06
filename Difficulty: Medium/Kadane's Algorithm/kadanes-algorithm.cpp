//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int n=(int)arr.size();
        
        int i=0;
        int j=0;
        int s=0;
        int res=INT_MIN;
        while(j<n)
        {
            s+=arr[j];
            while(i<=j && s<0)
            {
                s-=arr[i];
                i++;
            }
            if(i<=j)
            res=max(res,s);
            j++;
        }
        res=max(res,*max_element(arr.begin(),arr.end()));
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends