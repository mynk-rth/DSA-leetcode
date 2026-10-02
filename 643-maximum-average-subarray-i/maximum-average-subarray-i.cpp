class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        queue<int> q;
        long long sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
            sum += nums[i];
        }

        long long maxSum = sum;

        // Sliding window
        for (int i = k; i < nums.size(); i++) {

            // Front element remove karo
            sum -= q.front();
            q.pop();

            // New element add karo
            q.push(nums[i]);
            sum += nums[i];

            // Maximum sum update karo
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};