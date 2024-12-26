class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int check(int st, int len, int low, int high)
    {
        len--;
        string s = to_string(st);
        while (len--)
        {
            s += (s.back() + 1);
        }
        int num = stoi(s);
        if (num >= low && num <= high)
            return num;
        return -1;
    }
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int len = 2; len <= 9; len++)
        {
            for (int st = 1; st <= 9 - len + 1; st++)
            {
                int val = check(st, len, low, high);
                if (val != -1)
                    ans.push_back(val);
            }
        }
        return ans;
    }
};