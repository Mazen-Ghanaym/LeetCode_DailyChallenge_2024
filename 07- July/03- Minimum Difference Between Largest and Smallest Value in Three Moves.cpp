class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int mnv = INT_MAX;
        // 3 from start
        mnv = min(mnv, nums.back() - nums[3]);
        // 3 from end
        mnv = min(mnv, nums[n - 4] - nums.front());
        // 2 from start 1 from end
        mnv = min(mnv, nums[n - 2] - nums[2]);
        // 1 from start 2 from end
        mnv = min(mnv, nums[n - 3] - nums[1]);
        return mnv;
    }
};