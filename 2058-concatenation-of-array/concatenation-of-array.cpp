class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>  ans;
        for (int i : nums) {             
            ans.push_back(i);            //  ans = [ 1 2 1 1 2 1]
        }
        for (int i : nums) {       
            ans.push_back(i);
        }
        return ans;
        
    }
};  




