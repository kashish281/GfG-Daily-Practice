//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     string addStrings(string& num1,string& num2) {
        string result;
        int carry = 0;
        int i = num1.size() - 1,j = num2.size() - 1;
        int digit1,digit2,sum;
        while (i >= 0 || j >= 0 || carry > 0) {
            digit1 = (i >= 0) ? num1[i] - '0' : 0;
            digit2 = (j >= 0) ? num2[j] - '0' : 0;
            sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0'); 
            carry = sum / 10; 
            i--;
            j--;
        }

        reverse(result.begin(), result.end()); 
        return result;
    }
    string minSum(vector<int> &arr) {
        // code here
        vector<int> freq(10,0);
        for(int i:arr)
         freq[i]++;
        string s1,s2;
        int turn=0;
        for(int i=1;i<10;i++){
            if(freq[i]==0)
             continue;
            while(freq[i]>0){
                if(turn==0){
                    s1.push_back(i+'0');
                    turn=1;
                }
                else{
                    s2.push_back(i+'0');
                    turn=0;
                }
                freq[i]--;
            }
        }
        string res =addStrings(s1,s2);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends