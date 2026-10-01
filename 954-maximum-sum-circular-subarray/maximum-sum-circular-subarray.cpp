class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        // Array ko circular handle karne ke liye
        // prefix sum of 2*n elements
        vector<long long> prefix(2 * n + 1, 0);

        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + nums[i % n];
        }

        deque<int> dq;

        int ans = INT_MIN;

        for (int i = 0; i <= 2 * n; i++) {

            // Subarray ki length n se zyada nahi honi chahiye
            while (!dq.empty() && dq.front() < i - n) {
                dq.pop_front();
            }

            // Valid subarray se maximum sum
            if (!dq.empty()) {
                ans = max(ans, (int)(prefix[i] - prefix[dq.front()]));
            }

            // Useless prefix values remove karo
            while (!dq.empty() &&
                   prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }

            // Current prefix index add karo
            dq.push_back(i);
        }

        return ans;
    }
};