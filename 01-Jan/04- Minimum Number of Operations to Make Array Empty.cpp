// first solution
class Solution
{
public:
#define ll long long
    int minOperations(vector<int> &nums)
    {
        vector<int> dp(1e5 + 2);
        dp[1] = 0, dp[2] = 1, dp[3] = 1, dp[4] = 2;
        for (int i = 5; i <= 1e5; i++)
        {
            dp[i] = min(dp[i - 2], dp[i - 3]) + 1;
        }
        map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        ll ans = 0;
        for (auto it : freq)
        {
            if (it.second == 1)
                return -1;
            ans += dp[it.second];
        }
        return ans;
    }
};

// second solution
class Solution
{
public:
#define ll long long
    int minOperations(vector<int> &nums)
    {
        map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        ll ans = 0;
        for (auto [key, value] : freq)
        {
            cout << key << " " << value << "\n";
            if (value == 1)
                return -1;
            int cnt = 0;
            if (value > 4)
            {
                cnt = (value - 4 + 2) / 3; // = ceil((value - 4) / 3)
                value -= cnt * 3;
            }
            if (value == 2 || value == 3)
                cnt++;
            else
                cnt += 2;
            cout << key << " " << value << " " << cnt << "\n";
            ans += cnt;
        }
        return ans;
    }
};

// second solution optimized
class Solution
{
public:
#define ll long long
    int minOperations(vector<int> &nums)
    {
        map<int, int> freq;
        for (auto it : nums)
            freq[it]++;
        ll ans = 0;
        for (auto [key, value] : freq)
        {
            if (value == 1)
                return -1;
            int cnt = value / 3;
            cnt += (value % 3 ? 1 : 0);
            ans += cnt;
        }
        return ans;
    }
};