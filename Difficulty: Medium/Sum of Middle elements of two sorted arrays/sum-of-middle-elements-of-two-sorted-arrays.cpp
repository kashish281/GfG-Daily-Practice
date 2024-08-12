//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
          int n = arr1.size()+arr2.size();
        int middle = n/2+(n%2);
        int i=0,j=0;
        int add = 0;
        while(middle){
            while(i<arr1.size() && j<arr2.size() && middle){
                middle--;
                if(arr1[i]<=arr2[j]){
                    add=arr1[i];
                    i++;
                }
                else{
                    add=arr2[j];
                    j++;
                }
            }
            while(j<arr2.size() && middle){
                middle--;
                add=arr2[j];
                j++;
            }
            while(i<arr1.size() && middle){
                middle--;
                add=arr1[i];
                i++;
            }
        }
        int next = 0;
        if(i<arr1.size() && j<arr2.size()){
            next = min(arr1[i],arr2[j]);
        }
        else if(i<arr1.size()){
            next = arr1[i];
        }
        else{
            next = arr2[j];
        }
        return add+next;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends