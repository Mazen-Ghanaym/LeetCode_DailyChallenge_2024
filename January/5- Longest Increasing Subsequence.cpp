class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        multiset<int> st;
        int mx_len = 0;

        for(auto it : nums){
            st.insert(it);
            auto i = st.lower_bound(it);
            i++;
            if(i != st.end()) st.erase(i);
            mx_len = max(mx_len, (int)st.size());
        }
        return mx_len;
    }
};