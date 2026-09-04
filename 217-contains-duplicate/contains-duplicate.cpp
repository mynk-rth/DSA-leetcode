class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> v;
        for ( int i : nums ){
            if(v.count(i)){
                return true;
            }
            v.insert(i);
        }
        return false;
    }
};