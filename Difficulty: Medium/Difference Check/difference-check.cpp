class Solution {
  public:
      int timeToSeconds(string &time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr) {
        vector<int> secondsList;
        
        // Convert all time strings to seconds
        for (string &time : arr) {
            secondsList.push_back(timeToSeconds(time));
        }

        // Sort the seconds
        sort(secondsList.begin(), secondsList.end());

        int minDiff = INT_MAX;
        int n = secondsList.size();

        // Check difference between consecutive times
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, secondsList[i] - secondsList[i - 1]);
        }

        // Check the wrap-around difference (24 * 3600 = 86400)
        int wrapAroundDiff = 86400 - secondsList[n - 1] + secondsList[0];
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
