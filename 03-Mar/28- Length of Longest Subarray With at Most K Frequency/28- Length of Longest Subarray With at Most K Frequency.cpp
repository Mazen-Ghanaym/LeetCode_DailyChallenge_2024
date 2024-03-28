class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;
        int mx = 0, l = 0, r = 0;
        int n = nums.size();
        while(r < n){
            mp[nums[r]]++;
            while(l <= r && mp[nums[r]] > k){
                mp[nums[l++]]--;
            }
            r++;
            mx = max(mx, r - l);
        }
        return mx;
    }
};