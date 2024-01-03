class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt_before = 0,cnt_curr = 0;
        int sz = bank.size();
        int sum=0;
        for(int i = 0; i < sz; i++){
            for(auto it: bank[i]){
                cnt_curr += (it=='1');
            }
            if(cnt_curr != 0){
                sum += cnt_curr*cnt_before;
                cnt_before = cnt_curr;
                cnt_curr = 0;
            }
        }
        return sum;
    }
};