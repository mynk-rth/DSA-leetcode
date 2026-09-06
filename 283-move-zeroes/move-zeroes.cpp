class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int count = 0;
        for ( int i : nums){
            if (i != 0){
                ans.push_back(i);
            }
            else {
                count++;;
            }
        }
        while(count){
            ans.push_back(0);
            count--;
        }
        nums=ans;
    }
};