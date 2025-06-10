class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.size(), ans = 0;
        bool dup = false;
        unordered_map<char, int> m;
        for(char &i: s) m[i]++;
        for(char &i: s)
        {
            if(m[i] > 1) dup = true;
            ans += n - m[i];
        }
        return (ans/2)+dup;
    }
};
