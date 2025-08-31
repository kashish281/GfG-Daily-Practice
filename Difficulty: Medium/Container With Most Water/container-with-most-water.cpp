class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
            int left = 0;
        int right = arr.size() - 1;
        int area = 0;
        
        while(left<=right){
            area = max(area, (right - left)*min(arr[right], arr[left]));
            
            if(arr[left]<arr[right]){
                left++;
            }
            else{
                right--;
            }
            
        }
        
        return area;
    }
};