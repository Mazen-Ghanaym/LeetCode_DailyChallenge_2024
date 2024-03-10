class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(1001);
        for(auto &it : nums1){
            if(freq[it] == 0)
                freq[it] = 1;
        }
        for(auto &it : nums2){
            if(freq[it] == 1)
                freq[it] = 2;
        }
        vector<int> ans;
        for(int i = 0; i <= 1000; i++)
            if(freq[i] == 2)
                ans.push_back(i);
        return ans;
    }
};