//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int miss = 1;
        int n = arr.size();
        for(int i = 0; i< n ; i++){
            if(arr[i] > 0){
                if(arr[i] == miss){
                    miss++;
                }
                else if(arr[i] == miss-1){
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return miss;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends