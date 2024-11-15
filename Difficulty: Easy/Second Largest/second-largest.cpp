//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        set<int> st(arr.begin(),arr.end());
        //put the values of the set to a vector
        vector<int> ans(st.begin(),st.end());
        //sort the vector
        sort(ans.begin(),ans.end());
        //return -1 if only 1 element is in the array        
        if(ans.size()==1){
            return -1;
        }
        else
        //return the second last emement for the 2nd largest element 
        return ans[ans.size()-2];
        
    }
};

//{ Driver Code Starts.

int main() {
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends