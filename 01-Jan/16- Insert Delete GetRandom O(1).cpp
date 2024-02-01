#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class RandomizedSet
{
public:
    #define ordered_set tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set st;
    RandomizedSet()
    {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool insert(int val)
    {
        if (st.find(val) != st.end())
            return false;
        else
        {
            st.insert(val);
            return true;
        }
    }

    bool remove(int val)
    {
        if (st.find(val) != st.end())
        {
            st.erase(val);
            return true;
        }
        else
            return false;
    }

    int getRandom()
    {
        int idx = rand() % st.size();
        int val = *st.find_by_order(idx);
        return val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */