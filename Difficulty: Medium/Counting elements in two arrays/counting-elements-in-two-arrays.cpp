class Solution {
  public:
      int bs(vector<int>& b,int&n){
        int s = 0;
        int e = b.size()-1;
        int m;
        while(s<=e){
            m = s + (e-s)/2;
            if(b[m]<=n){
                s = m + 1;
            }
            else{
                e = m-1;
            }
        }
        return s;
    }
    
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        sort(b.begin(), b.end());
        
        for(int i = 0;i<a.size();i++){
            int num = bs(b,a[i]);
            ans.push_back(num);
        }
        
        return ans;
    }
};