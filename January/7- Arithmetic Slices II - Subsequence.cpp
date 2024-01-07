class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>> vc(n);
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j>=0; j--){
                long long diff = (long long)nums[i] - nums[j]; // difference between two consective elements
                if(diff > INT_MAX || diff < INT_MIN)continue;
                vc[i][diff]+=1;
                if(vc[j].count(diff)){
                    vc[i][diff] += vc[j][diff];
                    ans += vc[j][diff];
                }
            }
        }
        return ans;
    }
};