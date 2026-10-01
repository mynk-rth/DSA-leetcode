class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        deque<int> dq;

        int left = n;
        int right = 0;

        // Left boundary
        for (int i = 0; i < n; i++) {

            while (!dq.empty() && nums[dq.back()] > nums[i]) {

                left = min(left, dq.back());

                dq.pop_back();
            }

            dq.push_back(i);
        }

        dq.clear();

        // Right boundary
        for (int i = n - 1; i >= 0; i--) {

            while (!dq.empty() && nums[dq.back()] < nums[i]) {

                right = max(right, dq.back());

                dq.pop_back();
            }

            dq.push_back(i);
        }

        if (right == 0)
            return 0;

        return right - left + 1;
    }
};