class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> addsum;          
        addsum.push_back(0);

        int sum = 0;

        for ( int i=0; i<n; i++ ){
            sum += nums[i];
            addsum.push_back(sum);          // 0 1 13 8 2 52 55
        } 

        int maxsum = INT_MIN;

        for( int i=0; i<n-k+1; i++ ){
            sum = addsum[i+k] - addsum[i] ;
            maxsum = max(maxsum,sum);
        }

        return (double)maxsum/k;
    }
};