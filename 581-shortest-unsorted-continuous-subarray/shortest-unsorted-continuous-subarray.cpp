class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1;           // starting index
        int right = -1;          // update last index  

        queue<int> q1;
        for(int x : nums){
            q1.push(x);
        }
            
        sort(nums.begin(),nums.end());
        queue<int> q2;
        for(int x : nums){
            q2.push(x);
        }

        for( int i=0; i<nums.size(); i++){
            if( q1.front() != q2.front()){
                if(left == -1){
                    left = i;
                }
                right = i;
            }
            q1.pop();                    
            q2.pop();
        }

        if(left == -1){
            return 0;
        }
        else {
            int ans = right - left + 1;
            return ans;
        }
    }
};