#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
#define ordered_set tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
    int findTheWinner(int n, int k)
    {
        ordered_set st;
        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
        }
        k--;
        int pos = 0;
        while (st.size() > 1)
        {
            pos = (pos + k) % (st.size());
            auto it = st.find_by_order(pos);
            st.erase(it);
        }
        return *st.find_by_order(0);
    }
};