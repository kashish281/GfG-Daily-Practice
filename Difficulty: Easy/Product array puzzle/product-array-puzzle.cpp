//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int zerofo=0;
            long long totalpro=1;
            for (int i:arr){
                if (i==0){
                    zerofo++;
                    continue;
                }
                else{
                totalpro*=i;}
            }
            int n=arr.size();
        
            for (int i=0;i<n;i++){
                if (arr[i]==0 && zerofo==1){
                    arr[i]=totalpro;
                }
                else if (zerofo>=1){
                    arr[i]=0;
                }
               
                else {
                    arr[i]=totalpro/arr[i];
                }
            }
            return arr;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends