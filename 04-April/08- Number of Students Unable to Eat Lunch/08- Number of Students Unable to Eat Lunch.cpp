class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int cnt1 = 0, cnt0 = 0;
        for (auto &it : students)
        {
            cnt1 += it;
            cnt0 += !it;
        }
        int sz = sandwiches.size();
        for (auto &it : sandwiches)
        {
            cnt1 -= it;
            cnt0 -= !it;
            if (cnt1 < 0 || cnt0 < 0)
                break;
            sz--;
        }
        return sz;
    }
};