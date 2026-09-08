class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
         int majorityElement_idx = nums.size()/2;

        return nums[majorityElement_idx] ;
        

    }
};