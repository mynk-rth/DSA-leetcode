class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        queue<int> q;
        int startIndex = -1;
        int endIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty()) {
                int prev = q.front();

                if (nums[i] < prev) {
                    if (startIndex == -1)
                        startIndex = i - 1;
                    endIndex = i;
                }

                q.pop();
            }

            q.push(nums[i]);
        }

        if (startIndex == -1)
            return 0;

        int Min = nums[startIndex];
        int Max = nums[startIndex];

        for (int i = startIndex; i <= endIndex; i++) {
            Min = min(Min, nums[i]);
            Max = max(Max, nums[i]);
        }

        while (startIndex > 0 && nums[startIndex - 1] > Min)
            startIndex--;

        while (endIndex < nums.size() - 1 && nums[endIndex + 1] < Max)
            endIndex++;

        return endIndex - startIndex + 1;
    }
};