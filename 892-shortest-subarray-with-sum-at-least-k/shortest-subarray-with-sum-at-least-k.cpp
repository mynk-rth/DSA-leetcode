class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);//prefix= 0 1 3 6

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }//prefix[3]= 3+3

        deque<int> dq;

        int ans = n + 1; //3

        for(int i = 0; i <= n; i++) {

            while(!dq.empty() &&
                  prefix[i] - prefix[dq.front()] >= k) { //6-0>=6

                ans = min(ans, i - dq.front());//ans=min(4,3)

                dq.pop_front();
            }

            while(!dq.empty() &&
                  prefix[i] <= prefix[dq.back()]) {// 6<=3

                dq.pop_back();
            }

            dq.push_back(i); // 1 2 3
        }

        return ans == n + 1 ? -1 : ans; //3==3
    }
};//[1,2,3] k=6