//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
         vector<int> v;
        int i = 0, cnt = 0;
        string s = "";
        while(i < str.length())
        {
            if(str[i] == '/' || str[i] == ',' || str[i] == ' ')
            {
                if(s != "")
                {
                    v.push_back(stoi(s));
                    s = "";
                }
            }
            else
            {
                s += str[i];
            }
            i++;
        }
        if(s != "")
        {
            v.push_back(stoi(s));
        }
        double a = v[0] + 0.0000, b = v[1] + 0.0000, c = v[2] + 0.0000, d = v[3] + 0.0000;
        string ans = "";
        if(a/b > c/d)
        {
            ans = ans + to_string(v[0]) + "/" + to_string(v[1]);
            return ans;
        }
        else if(c/d > a/b)
        {
            ans = ans + to_string(v[2]) + "/" + to_string(v[3]);
            return ans;
        }
        else
        {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends