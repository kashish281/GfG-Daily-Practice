//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
         int i,n, sum;
        sum =0;
        n=arr.size();
        int left[n]; int right[n]; int aux[n];
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        for(i=1;i<n;i++){
            left[i] = left[i-1]>arr[i]?left[i-1]:arr[i];  
        }
        
        for(i=n-2;i>=0;i--){
            right[i] = right[i+1]>arr[i]?right[i+1]:arr[i];  
        }
        
        for(i = 0;i<n;i++){
            aux[i]= left[i]>right[i]?(right[i] - arr[i]):( left[i]-arr[i]);
        }
        
        for(i = 0;i<n;i++){
            sum+=aux[i];
        }
        
        return sum;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends