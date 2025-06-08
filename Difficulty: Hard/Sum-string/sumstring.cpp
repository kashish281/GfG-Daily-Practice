class Solution {
  public:
  bool f(int idx, int prev1, int prev2, string s, int len, int curr){
        
        int currNumber = 0;
        for(int i = idx;i<s.size();i++){
            
            
            currNumber = currNumber*10 + s[i]-'0';
            if(i==s.size()-1 && (prev1+prev2==currNumber)) return true;
            if((prev1+prev2==currNumber) || prev1==-1 || prev2==-1 || len<=1){
                
              
                if(i+1<s.size() && s[i+1]=='0') continue;
                if(f(i+1,currNumber,prev1,s,len+1,currNumber)) return true;
            }
            
        }
        return false;
    }
    bool isSumString(string &s) {
        // code here
         int n = s.size();
        if(n<=2) return false;
      
        return f(0,-1,-1,s,0,0);
        
    }
};