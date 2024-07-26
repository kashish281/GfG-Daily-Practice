//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string removeSpaces(const string& str) {
        string result;
        for (char c : str) {
            if (!isspace(c)) {
                result += c;
            }
        }
        return result;
    }


    bool kPangram(string str, int k) {
        // code here
        str = removeSpaces(str);
        if(str.length() < 26) return false;
        unordered_map<char, int> maps;
        int remain = 0;
        int count = 0;
        for (int i = 0; i < str.length(); i++){
            if(maps[str[i]] == 0) {
                maps[str[i]] ++;
                count ++;
            }
            else if (maps[str[i]] == 1) remain++;
        }
        //cout << 26-count <<  " " << min(remain, k);
        return 26-count <= min(remain, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends