class Solution
{
public:
    template <typename T = int, int Base = 1>
    struct DSU
    {
#define sz(x) (int)x.size
        vector<T> parent, Gsize, nxt, tail, pos, roots;

        DSU(int MaxNodes)
        {
            parent = Gsize = roots = tail = pos = nxt =
                vector<T>(MaxNodes + Base);
            for (int i = Base; i < MaxNodes + Base; i++)
            {
                parent[i] = roots[i] = pos[i] = tail[i] = i;
                nxt[i] = -1, Gsize[i] = 1;
            }
        }

        T find_leader(int node)
        {
            return parent[node] =
                       (parent[node] == node ? node
                                             : find_leader(parent[node]));
        }

        bool is_same_sets(int u, int v)
        {
            return find_leader(u) == find_leader(v);
        }

        void union_sets(int u, int v)
        {
            int leader_u = find_leader(u), leader_v = find_leader(v);
            if (leader_u == leader_v)
                return;
            // make leader_u is the leader with the larger component
            if (Gsize[leader_u] < Gsize[leader_v])
                swap(leader_u, leader_v);
            int p = pos[leader_v];
            Gsize[leader_u] += Gsize[leader_v];
            parent[leader_v] = leader_u;
            roots[p] = roots.back();
            pos[roots[p]] = p;
            roots.pop_back();
            nxt[tail[leader_u]] = leader_v;
            tail[leader_u] = tail[leader_v];
        }

        void print()
        {
            for (int root = Base; root < sz(roots); root++)
            {
                for (int u = roots[root]; ~u; u = nxt[u])
                    cout << u << " \n"[!~nxt[u]];
            }
        }

        int get_size(int u) { return Gsize[find_leader(u)]; }

        int get_components_number() { return roots.size() - Base; }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU<int> dsua(n), dsub(n);
        sort(edges.rbegin(), edges.rend());
        int cnt = 0;
        for (auto &it : edges)
        {
            if (it[0] == 3)
            {
                if (dsua.is_same_sets(it[1], it[2]) && dsub.is_same_sets(it[1], it[2]))
                    cnt++;
                else
                {
                    dsua.union_sets(it[1], it[2]);
                    dsub.union_sets(it[1], it[2]);
                }
            }
            else if (it[0] == 2)
            {
                if (dsub.is_same_sets(it[1], it[2]))
                    cnt++;
                else
                    dsub.union_sets(it[1], it[2]);
            }
            else
            {
                if (dsua.is_same_sets(it[1], it[2]))
                    cnt++;
                else
                    dsua.union_sets(it[1], it[2]);
            }
        }
        return (dsua.get_components_number() == 1 && dsub.get_components_number() == 1 ? cnt : -1);
    }
};