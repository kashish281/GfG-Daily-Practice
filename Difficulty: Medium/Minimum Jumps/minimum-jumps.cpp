//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
          int n =arr.size();
        int jmp =0;
        int limit =INT_MIN;
        int end =0;
        for(int i =0;i< n;i++){
            limit =max(limit,i + arr[i]);
            if(i == end){
                end =limit;
                jmp++;
                
                if(end >= n-1){
                    return jmp;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends