//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
           int i=0, j=0, ans=0;
        while(k){
            if(i==arr1.size()){ans=arr2[j]; j++; k--;
               if(k==0){return ans;}
               continue;
            }
            if(j==arr2.size()){ans=arr1[i]; i++; k--;
               if(k==0){return ans;}
               continue;
            }
            if(arr1[i]>arr2[j]){ans=arr2[j]; j++; k--;}
            else if(arr1[i]<arr2[j]){ans=arr1[i]; i++; k--;}
            else{ans=arr1[i]; i++; j++; k-=2;}
            if(k<1){return ans;}
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends